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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.ID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Position = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Hand = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Status = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Alarm = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.TcpInfo = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.label30 = new System.Windows.Forms.Label();
            this.tBOHTID = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.bnSetStatusTime = new System.Windows.Forms.Button();
            this.tBPosTime = new System.Windows.Forms.TextBox();
            this.tBStatusTime = new System.Windows.Forms.TextBox();
            this.bnSetPosTime = new System.Windows.Forms.Button();
            this.label27 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.groupBox8.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ID,
            this.Position,
            this.Hand,
            this.Status,
            this.Alarm,
            this.TcpInfo});
            this.dataGridView1.Location = new System.Drawing.Point(3, 15);
            this.dataGridView1.MultiSelect = false;
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowHeadersVisible = false;
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridView1.Size = new System.Drawing.Size(353, 395);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.SelectionChanged += new System.EventHandler(this.dataGridView1_SelectionChanged);
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
            this.Position.Width = 80;
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
            this.groupBox8.Controls.Add(this.label30);
            this.groupBox8.Controls.Add(this.tBOHTID);
            this.groupBox8.Controls.Add(this.label9);
            this.groupBox8.Controls.Add(this.bnSetStatusTime);
            this.groupBox8.Controls.Add(this.tBPosTime);
            this.groupBox8.Controls.Add(this.tBStatusTime);
            this.groupBox8.Controls.Add(this.bnSetPosTime);
            this.groupBox8.Controls.Add(this.label27);
            this.groupBox8.Location = new System.Drawing.Point(362, 15);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(201, 136);
            this.groupBox8.TabIndex = 14;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Back Time Config";
            // 
            // label30
            // 
            this.label30.AutoSize = true;
            this.label30.Location = new System.Drawing.Point(14, 43);
            this.label30.Name = "label30";
            this.label30.Size = new System.Drawing.Size(47, 12);
            this.label30.TabIndex = 14;
            this.label30.Text = "OHT ID:";
            // 
            // tBOHTID
            // 
            this.tBOHTID.Location = new System.Drawing.Point(73, 40);
            this.tBOHTID.Name = "tBOHTID";
            this.tBOHTID.Size = new System.Drawing.Size(58, 21);
            this.tBOHTID.TabIndex = 13;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(14, 73);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(53, 12);
            this.label9.TabIndex = 5;
            this.label9.Text = "Position";
            // 
            // bnSetStatusTime
            // 
            this.bnSetStatusTime.Location = new System.Drawing.Point(137, 97);
            this.bnSetStatusTime.Name = "bnSetStatusTime";
            this.bnSetStatusTime.Size = new System.Drawing.Size(52, 23);
            this.bnSetStatusTime.TabIndex = 12;
            this.bnSetStatusTime.Text = "Set";
            this.bnSetStatusTime.UseVisualStyleBackColor = true;
            this.bnSetStatusTime.Click += new System.EventHandler(this.bnSetStatusTime_Click);
            // 
            // tBPosTime
            // 
            this.tBPosTime.Location = new System.Drawing.Point(73, 70);
            this.tBPosTime.Name = "tBPosTime";
            this.tBPosTime.Size = new System.Drawing.Size(58, 21);
            this.tBPosTime.TabIndex = 6;
            // 
            // tBStatusTime
            // 
            this.tBStatusTime.Location = new System.Drawing.Point(73, 97);
            this.tBStatusTime.Name = "tBStatusTime";
            this.tBStatusTime.Size = new System.Drawing.Size(58, 21);
            this.tBStatusTime.TabIndex = 11;
            // 
            // bnSetPosTime
            // 
            this.bnSetPosTime.Location = new System.Drawing.Point(137, 70);
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
            this.label27.Location = new System.Drawing.Point(14, 100);
            this.label27.Name = "label27";
            this.label27.Size = new System.Drawing.Size(41, 12);
            this.label27.TabIndex = 10;
            this.label27.Text = "Status";
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
            // OHTInfo
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox8);
            this.Controls.Add(this.dataGridView1);
            this.Name = "OHTInfo";
            this.Size = new System.Drawing.Size(812, 413);
            this.Load += new System.EventHandler(this.OHTInfo_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn ID;
        private System.Windows.Forms.DataGridViewTextBoxColumn Position;
        private System.Windows.Forms.DataGridViewTextBoxColumn Hand;
        private System.Windows.Forms.DataGridViewTextBoxColumn Status;
        private System.Windows.Forms.DataGridViewTextBoxColumn Alarm;
        private System.Windows.Forms.DataGridViewTextBoxColumn TcpInfo;
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
    }
}
