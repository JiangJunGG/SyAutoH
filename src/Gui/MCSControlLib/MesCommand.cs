﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MCSControlLib
{
    public partial class MesCommand : UserControl, IMcsControlBase
    {
        private GuiAccess.DataHubCli m_dataHub = null;
        public MesCommand()
        {
            InitializeComponent();
        }

        public GuiAccess.DataHubCli DataHub
        {
            set
            {
                m_dataHub = value;
            }
            get
            {
                return m_dataHub;
            }
        }

        public void ProcessGuiData(List<MCS.GuiDataItem> list)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("MesCommand Test");
        }
    }
}