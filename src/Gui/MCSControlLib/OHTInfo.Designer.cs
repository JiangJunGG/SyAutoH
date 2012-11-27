﻿namespace MCSControlLib
{
    partial class OHTInfo
    {
        /// <summary> 
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            this.dataGridViewOHTInfo = new System.Windows.Forms.DataGridView();
            this.ID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Position = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Hand = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Status = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Alarm = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.TcpInfo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.bnSetStatusTime = new System.Windows.Forms.Button();
            this.tBPosTime = new System.Windows.Forms.TextBox();
            this.tBStatusTime = new System.Windows.Forms.TextBox();
            this.bnSetPosTime = new System.Windows.Forms.Button();
            this.label27 = new System.Windows.Forms.Label();
            this.label30 = new System.Windows.Forms.Label();
            this.tBOHTID = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox10 = new System.Windows.Forms.GroupBox();
            this.bnPlace = new System.Windows.Forms.Button();
            this.label29 = new System.Windows.Forms.Label();
            this.bnPick = new System.Windows.Forms.Button();
            this.tBBuffID = new System.Windows.Forms.TextBox();
            this.dataGridViewKeyPos = new System.Windows.Forms.DataGridView();
            this.label2 = new System.Windows.Forms.Label();
            this.linkLabelRefresh = new System.Windows.Forms.LinkLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.dataGridViewPath = new System.Windows.Forms.DataGridView();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.linkLabel2 = new System.Windows.Forms.LinkLabel();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewOHTInfo)).BeginInit();
            this.groupBox8.SuspendLayout();
            this.groupBox10.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewKeyPos)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPath)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewOHTInfo
            // 
            this.dataGridViewOHTInfo.AllowUserToAddRows = false;
            this.dataGridViewOHTInfo.AllowUserToDeleteRows = false;
            this.dataGridViewOHTInfo.AllowUserToResizeRows = false;
            this.dataGridViewOHTInfo.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.dataGridViewOHTInfo.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dataGridViewOHTInfo.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewOHTInfo.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewOHTInfo.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewOHTInfo.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ID,
            this.Position,
            this.Hand,
            this.Status,
            this.Alarm,
            this.TcpInfo});
            this.dataGridViewOHTInfo.Location = new System.Drawing.Point(3, 15);
            this.dataGridViewOHTInfo.MultiSelect = false;
            this.dataGridViewOHTInfo.Name = "dataGridViewOHTInfo";
            this.dataGridViewOHTInfo.ReadOnly = true;
            this.dataGridViewOHTInfo.RowHeadersVisible = false;
            this.dataGridViewOHTInfo.RowTemplate.Height = 23;
            this.dataGridViewOHTInfo.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewOHTInfo.Size = new System.Drawing.Size(326, 314);
            this.dataGridViewOHTInfo.TabIndex = 0;
            this.dataGridViewOHTInfo.SelectionChanged += new System.EventHandler(this.dataGridView1_SelectionChanged);
            // 
            // ID
            // 
            this.ID.DataPropertyName = "ID";
            this.ID.HeaderText = "ID";
            this.ID.Name = "ID";
            this.ID.ReadOnly = true;
            this.ID.Width = 40;
            // 
            // Position
            // 
            this.Position.DataPropertyName = "Position";
            this.Position.FillWeight = 80F;
            this.Position.HeaderText = "Position";
            this.Position.Name = "Position";
            this.Position.ReadOnly = true;
            this.Position.Width = 60;
            // 
            // Hand
            // 
            this.Hand.DataPropertyName = "Hand";
            this.Hand.HeaderText = "Hand";
            this.Hand.Name = "Hand";
            this.Hand.ReadOnly = true;
            this.Hand.Width = 40;
            // 
            // Status
            // 
            this.Status.DataPropertyName = "Status";
            this.Status.HeaderText = "Status";
            this.Status.Name = "Status";
            this.Status.ReadOnly = true;
            this.Status.Width = 45;
            // 
            // Alarm
            // 
            this.Alarm.DataPropertyName = "Alarm";
            this.Alarm.HeaderText = "Alarm";
            this.Alarm.Name = "Alarm";
            this.Alarm.ReadOnly = true;
            this.Alarm.Width = 40;
            // 
            // TcpInfo
            // 
            this.TcpInfo.DataPropertyName = "TcpInfo";
            this.TcpInfo.HeaderText = "TcpInfo";
            this.TcpInfo.Name = "TcpInfo";
            this.TcpInfo.ReadOnly = true;
            // 
            // groupBox8
            // 
            this.groupBox8.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox8.Controls.Add(this.label9);
            this.groupBox8.Controls.Add(this.bnSetStatusTime);
            this.groupBox8.Controls.Add(this.tBPosTime);
            this.groupBox8.Controls.Add(this.tBStatusTime);
            this.groupBox8.Controls.Add(this.bnSetPosTime);
            this.groupBox8.Controls.Add(this.label27);
            this.groupBox8.Location = new System.Drawing.Point(5, 334);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(223, 79);
            this.groupBox8.TabIndex = 14;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Back Time Config";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(17, 20);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(53, 12);
            this.label9.TabIndex = 5;
            this.label9.Text = "Position";
            // 
            // bnSetStatusTime
            // 
            this.bnSetStatusTime.Location = new System.Drawing.Point(140, 44);
            this.bnSetStatusTime.Name = "bnSetStatusTime";
            this.bnSetStatusTime.Size = new System.Drawing.Size(52, 23);
            this.bnSetStatusTime.TabIndex = 12;
            this.bnSetStatusTime.Text = "Set";
            this.bnSetStatusTime.UseVisualStyleBackColor = true;
            this.bnSetStatusTime.Click += new System.EventHandler(this.bnSetStatusTime_Click);
            // 
            // tBPosTime
            // 
            this.tBPosTime.Location = new System.Drawing.Point(76, 17);
            this.tBPosTime.Name = "tBPosTime";
            this.tBPosTime.Size = new System.Drawing.Size(58, 21);
            this.tBPosTime.TabIndex = 6;
            // 
            // tBStatusTime
            // 
            this.tBStatusTime.Location = new System.Drawing.Point(76, 44);
            this.tBStatusTime.Name = "tBStatusTime";
            this.tBStatusTime.Size = new System.Drawing.Size(58, 21);
            this.tBStatusTime.TabIndex = 11;
            // 
            // bnSetPosTime
            // 
            this.bnSetPosTime.Location = new System.Drawing.Point(140, 17);
            this.bnSetPosTime.Name = "bnSetPosTime";
            this.bnSetPosTime.Size = new System.Drawing.Size(52, 23);
            this.bnSetPosTime.TabIndex = 7;
            this.bnSetPosTime.Text = "Set";
            this.bnSetPosTime.UseVisualStyleBackColor = true;
            this.bnSetPosTime.Click += new System.EventHandler(this.bnSetPosTime_Click);
            // 
            // label27
            // 
            this.label27.AutoSize = true;
            this.label27.Location = new System.Drawing.Point(17, 47);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(41, 12);
            this.label27.TabIndex = 10;
            this.label27.Text = "Status";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.Location = new System.Drawing.Point(353, 15);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(47, 12);
            this.label30.TabIndex = 14;
            this.label30.Text = "OHT ID:";
            // 
            // tBOHTID
            // 
            this.tBOHTID.Location = new System.Drawing.Point(412, 12);
            this.tBOHTID.Name = "tBOHTID";
            this.tBOHTID.Size = new System.Drawing.Size(58, 21);
            this.tBOHTID.TabIndex = 13;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(3, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 12);
            this.label1.TabIndex = 15;
            this.label1.Text = "OHT List:";
            // 
            // groupBox10
            // 
            this.groupBox10.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox10.Controls.Add(this.bnPlace);
            this.groupBox10.Controls.Add(this.label29);
            this.groupBox10.Controls.Add(this.bnPick);
            this.groupBox10.Controls.Add(this.tBBuffID);
            this.groupBox10.Location = new System.Drawing.Point(5, 418);
            this.groupBox10.Name = "groupBox10";
            this.groupBox10.Size = new System.Drawing.Size(223, 52);
            this.groupBox10.TabIndex = 22;
            this.groupBox10.TabStop = false;
            this.groupBox10.Text = "Foup Handing";
            // 
            // bnPlace
            // 
            this.bnPlace.Location = new System.Drawing.Point(162, 18);
            this.bnPlace.Name = "bnPlace";
            this.bnPlace.Size = new System.Drawing.Size(55, 23);
            this.bnPlace.TabIndex = 14;
            this.bnPlace.Text = "Place";
            this.bnPlace.UseVisualStyleBackColor = true;
            this.bnPlace.Click += new System.EventHandler(this.bnPlace_Click);
            // 
            // label29
            // 
            this.label29.AutoSize = true;
            this.label29.Location = new System.Drawing.Point(8, 23);
            this.label29.Name = "label29";
            this.label29.Size = new System.Drawing.Size(41, 12);
            this.label29.TabIndex = 13;
            this.label29.Text = "Buf ID";
            // 
            // bnPick
            // 
            this.bnPick.Location = new System.Drawing.Point(112, 18);
            this.bnPick.Name = "bnPick";
            this.bnPick.Size = new System.Drawing.Size(44, 23);
            this.bnPick.TabIndex = 13;
            this.bnPick.Text = "Pick";
            this.bnPick.UseVisualStyleBackColor = true;
            this.bnPick.Click += new System.EventHandler(this.bnPick_Click);
            // 
            // tBBuffID
            // 
            this.tBBuffID.Location = new System.Drawing.Point(55, 20);
            this.tBBuffID.Name = "tBBuffID";
            this.tBBuffID.Size = new System.Drawing.Size(51, 21);
            this.tBBuffID.TabIndex = 14;
            // 
            // dataGridViewKeyPos
            // 
            this.dataGridViewKeyPos.AllowUserToAddRows = false;
            this.dataGridViewKeyPos.AllowUserToDeleteRows = false;
            this.dataGridViewKeyPos.AllowUserToResizeRows = false;
            this.dataGridViewKeyPos.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.dataGridViewKeyPos.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dataGridViewKeyPos.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewKeyPos.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridViewKeyPos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewKeyPos.Location = new System.Drawing.Point(484, 32);
            this.dataGridViewKeyPos.MultiSelect = false;
            this.dataGridViewKeyPos.Name = "dataGridViewKeyPos";
            this.dataGridViewKeyPos.ReadOnly = true;
            this.dataGridViewKeyPos.RowHeadersVisible = false;
            this.dataGridViewKeyPos.RowTemplate.Height = 23;
            this.dataGridViewKeyPos.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewKeyPos.Size = new System.Drawing.Size(239, 438);
            this.dataGridViewKeyPos.TabIndex = 23;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(482, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(137, 12);
            this.label2.TabIndex = 24;
            this.label2.Text = "Locations && Key Points";
            // 
            // linkLabelRefresh
            // 
            this.linkLabelRefresh.AutoSize = true;
            this.linkLabelRefresh.Location = new System.Drawing.Point(676, 15);
            this.linkLabelRefresh.Name = "linkLabelRefresh";
            this.linkLabelRefresh.Size = new System.Drawing.Size(47, 12);
            this.linkLabelRefresh.TabIndex = 25;
            this.linkLabelRefresh.TabStop = true;
            this.linkLabelRefresh.Text = "Refresh";
            this.linkLabelRefresh.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabelRefresh_LinkClicked);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Location = new System.Drawing.Point(347, 39);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(131, 51);
            this.groupBox1.TabIndex = 26;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "From";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 23);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 15;
            this.label3.Text = "Position";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(65, 20);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(58, 21);
            this.textBox1.TabIndex = 16;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.textBox2);
            this.groupBox2.Location = new System.Drawing.Point(347, 96);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(131, 50);
            this.groupBox2.TabIndex = 27;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "To";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 23);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 12);
            this.label4.TabIndex = 15;
            this.label4.Text = "Position";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(65, 20);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(58, 21);
            this.textBox2.TabIndex = 16;
            // 
            // button1
            // 
            this.button1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button1.Location = new System.Drawing.Point(28, 289);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 28;
            this.button1.Text = "Set Path";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(27, 20);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(51, 23);
            this.button2.TabIndex = 29;
            this.button2.Text = "Move";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(27, 68);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(51, 23);
            this.button3.TabIndex = 30;
            this.button3.Text = "Pause";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(27, 97);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(51, 23);
            this.button4.TabIndex = 31;
            this.button4.Text = "Stop";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox3.Controls.Add(this.dataGridViewPath);
            this.groupBox3.Controls.Add(this.button1);
            this.groupBox3.Location = new System.Drawing.Point(347, 152);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(131, 318);
            this.groupBox3.TabIndex = 32;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Path";
            // 
            // dataGridViewPath
            // 
            this.dataGridViewPath.AllowUserToAddRows = false;
            this.dataGridViewPath.AllowUserToDeleteRows = false;
            this.dataGridViewPath.AllowUserToResizeRows = false;
            this.dataGridViewPath.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.dataGridViewPath.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.dataGridViewPath.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewPath.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewPath.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewPath.Location = new System.Drawing.Point(8, 18);
            this.dataGridViewPath.MultiSelect = false;
            this.dataGridViewPath.Name = "dataGridViewPath";
            this.dataGridViewPath.ReadOnly = true;
            this.dataGridViewPath.RowHeadersVisible = false;
            this.dataGridViewPath.RowTemplate.Height = 23;
            this.dataGridViewPath.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewPath.Size = new System.Drawing.Size(115, 265);
            this.dataGridViewPath.TabIndex = 33;
            // 
            // groupBox4
            // 
            this.groupBox4.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.groupBox4.Controls.Add(this.button2);
            this.groupBox4.Controls.Add(this.button3);
            this.groupBox4.Controls.Add(this.button4);
            this.groupBox4.Location = new System.Drawing.Point(235, 339);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(94, 131);
            this.groupBox4.TabIndex = 33;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Move Control";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(482, 15);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(53, 12);
            this.linkLabel1.TabIndex = 34;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Set From";
            // 
            // linkLabel2
            // 
            this.linkLabel2.AutoSize = true;
            this.linkLabel2.Location = new System.Drawing.Point(578, 15);
            this.linkLabel2.Name = "linkLabel2";
            this.linkLabel2.Size = new System.Drawing.Size(41, 12);
            this.linkLabel2.TabIndex = 35;
            this.linkLabel2.TabStop = true;
            this.linkLabel2.Text = "Set To";
            // 
            // OHTInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.linkLabel2);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.label30);
            this.Controls.Add(this.tBOHTID);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox10);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.linkLabelRefresh);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.dataGridViewKeyPos);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox8);
            this.Controls.Add(this.dataGridViewOHTInfo);
            this.Name = "OHTInfo";
            this.Size = new System.Drawing.Size(734, 473);
            this.Load += new System.EventHandler(this.OHTInfo_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewOHTInfo)).EndInit();
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.groupBox10.ResumeLayout(false);
            this.groupBox10.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewKeyPos)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPath)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewOHTInfo;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.Label label30;
        private System.Windows.Forms.TextBox tBOHTID;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button bnSetStatusTime;
        private System.Windows.Forms.TextBox tBPosTime;
        private System.Windows.Forms.TextBox tBStatusTime;
        private System.Windows.Forms.Button bnSetPosTime;
        private System.Windows.Forms.Label label27;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridViewTextBoxColumn ID;
        private System.Windows.Forms.DataGridViewTextBoxColumn Position;
        private System.Windows.Forms.DataGridViewTextBoxColumn Hand;
        private System.Windows.Forms.DataGridViewTextBoxColumn Status;
        private System.Windows.Forms.DataGridViewTextBoxColumn Alarm;
        private System.Windows.Forms.DataGridViewTextBoxColumn TcpInfo;
        private System.Windows.Forms.GroupBox groupBox10;
        private System.Windows.Forms.Button bnPlace;
        private System.Windows.Forms.Label label29;
        private System.Windows.Forms.Button bnPick;
        private System.Windows.Forms.TextBox tBBuffID;
        private System.Windows.Forms.DataGridView dataGridViewKeyPos;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.LinkLabel linkLabelRefresh;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.DataGridView dataGridViewPath;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.LinkLabel linkLabel2;
    }
}
