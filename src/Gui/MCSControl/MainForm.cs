﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using MCSControlLib;

namespace MCSControl
{
    public partial class MainForm : Form
    {
        public int Session
        {
            get { return m_nSession; }
            set { m_nSession = value; }
        }
        private string m_strUserName = "";
        public string UserName
        {
            get { return m_strUserName; }
            set { m_strUserName = value; }
        }
        private bool m_bNeedLogin = false;
        public bool NeedLogin
        {
            get { return m_bNeedLogin; }
        }

        private GuiAccess.DataHubCli m_dataHub = new GuiAccess.DataHubCli();
        private Queue<MCS.GuiDataItem> buf = new Queue<MCS.GuiDataItem>();
        private int m_nSession = -1;
        private Dictionary<string, UserControl> m_dictMcsControl = new Dictionary<string, UserControl>();
        private UserControl _ctrl = null;
        private IMcsControlBase m_ctrlBase = null;

        public MainForm()
        {
            InitializeComponent();
        }

        private void GuiDataUpdate(MCS.GuiDataItem item)
        {
            lock (buf)
            {
                buf.Enqueue(item);
            }
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            m_dataHub.ConnectServer();
            toolStripStatusLabel_User.Text = "Logined User: " + m_strUserName + " ";
            m_dataHub.DataUpdater += new GuiAccess.DataUpdaterHander(GuiDataUpdate);
            m_dataHub.Async_SetCallBack();
            m_dataHub.Session = m_nSession;

            InitMcsControlDictionary();
            this.timer1.Start();
        }

        private void InitMcsControlDictionary()
        {
            m_dictMcsControl.Add("nodeOHTInfo", new OHTInfo() );
            m_dictMcsControl.Add("nodeMesCommand", new MesCommand() );
        }

        private void logoutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_bNeedLogin = true;
            this.Close();
        }

        private void closeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_bNeedLogin = false;
            this.Close();
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            string strSelect = e.Node.Name;
            bool bFind = m_dictMcsControl.TryGetValue(strSelect, out _ctrl);

            if (null != _ctrl)
            {
                m_ctrlBase = _ctrl as IMcsControlBase;
                m_ctrlBase.DataHub = m_dataHub;
                _ctrl.Location = new Point(10, 10);
                _ctrl.Size = new Size(10, 10);
                this.splitContainer1.Panel2.Controls.Clear();
                this.splitContainer1.Panel2.Controls.Add(_ctrl);
                _ctrl.Dock = DockStyle.Fill;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            List<MCS.GuiDataItem> listGuiData = new List<MCS.GuiDataItem>();
            lock (buf)
            {
                while (buf.Count != 0)
                {
                    MCS.GuiDataItem item = buf.Dequeue();
                    listGuiData.Add(item);
                }
            }

            if (null != m_ctrlBase)
            {
                m_ctrlBase.ProcessGuiData(listGuiData);
            }

            DateTime dtNow = DateTime.Now;
            TimeSpan span = dtNow - m_dataHub.UpdateTime;
            if (span.TotalSeconds > 5)
            {
                m_dataHub.Async_SetCallBack();
            }
        }
    }
}