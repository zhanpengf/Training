namespace BusinessManager
{
    partial class SellHistoryForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonSave = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonChart = new System.Windows.Forms.Button();
            this.buttonUpdateLocation = new System.Windows.Forms.Button();
            this.buttonSell = new System.Windows.Forms.Button();
            this.buttonAddNewToInv = new System.Windows.Forms.Button();
            this.buttonRefresh = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonAddShipping = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.numericCost = new System.Windows.Forms.NumericUpDown();
            this.label6 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.comboBoxShippingType = new System.Windows.Forms.ComboBox();
            this.buttonUpdateSum = new System.Windows.Forms.Button();
            this.dataGridViewSum = new System.Windows.Forms.DataGridView();
            this.labelItemsSold = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.labelProfit = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.dateTimePickerTo = new System.Windows.Forms.DateTimePicker();
            this.label1 = new System.Windows.Forms.Label();
            this.dateTimePickerFrom = new System.Windows.Forms.DateTimePicker();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.panel1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericCost)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSum)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(609, 127);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(75, 23);
            this.buttonSave.TabIndex = 4;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(1242, 309);
            this.dataGridView1.TabIndex = 3;
            this.dataGridView1.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);
            this.dataGridView1.ColumnWidthChanged += new System.Windows.Forms.DataGridViewColumnEventHandler(this.dataGridView1_ColumnWidthChanged);
            this.dataGridView1.CurrentCellDirtyStateChanged += new System.EventHandler(this.dataGridView1_CurrentCellDirtyStateChanged);
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.buttonChart);
            this.panel1.Controls.Add(this.buttonUpdateLocation);
            this.panel1.Controls.Add(this.buttonSell);
            this.panel1.Controls.Add(this.buttonAddNewToInv);
            this.panel1.Controls.Add(this.buttonRefresh);
            this.panel1.Controls.Add(this.groupBox1);
            this.panel1.Controls.Add(this.buttonUpdateSum);
            this.panel1.Controls.Add(this.dataGridViewSum);
            this.panel1.Controls.Add(this.labelItemsSold);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.labelProfit);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.dateTimePickerTo);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.dateTimePickerFrom);
            this.panel1.Controls.Add(this.buttonSave);
            this.panel1.Location = new System.Drawing.Point(0, 312);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1242, 200);
            this.panel1.TabIndex = 6;
            // 
            // buttonChart
            // 
            this.buttonChart.Location = new System.Drawing.Point(485, 40);
            this.buttonChart.Name = "buttonChart";
            this.buttonChart.Size = new System.Drawing.Size(75, 23);
            this.buttonChart.TabIndex = 20;
            this.buttonChart.Text = "Chart";
            this.buttonChart.UseVisualStyleBackColor = true;
            this.buttonChart.Click += new System.EventHandler(this.buttonChart_Click);
            // 
            // buttonUpdateLocation
            // 
            this.buttonUpdateLocation.Location = new System.Drawing.Point(342, 69);
            this.buttonUpdateLocation.Name = "buttonUpdateLocation";
            this.buttonUpdateLocation.Size = new System.Drawing.Size(137, 23);
            this.buttonUpdateLocation.TabIndex = 19;
            this.buttonUpdateLocation.Text = "Update Location";
            this.buttonUpdateLocation.UseVisualStyleBackColor = true;
            this.buttonUpdateLocation.Click += new System.EventHandler(this.buttonUpdateLocation_Click);
            // 
            // buttonSell
            // 
            this.buttonSell.Location = new System.Drawing.Point(342, 98);
            this.buttonSell.Name = "buttonSell";
            this.buttonSell.Size = new System.Drawing.Size(137, 23);
            this.buttonSell.TabIndex = 18;
            this.buttonSell.Text = "Sell";
            this.buttonSell.UseVisualStyleBackColor = true;
            this.buttonSell.Click += new System.EventHandler(this.buttonSell_Click);
            // 
            // buttonAddNewToInv
            // 
            this.buttonAddNewToInv.Location = new System.Drawing.Point(342, 40);
            this.buttonAddNewToInv.Name = "buttonAddNewToInv";
            this.buttonAddNewToInv.Size = new System.Drawing.Size(137, 23);
            this.buttonAddNewToInv.TabIndex = 17;
            this.buttonAddNewToInv.Text = "Add New to Inventory";
            this.buttonAddNewToInv.UseVisualStyleBackColor = true;
            this.buttonAddNewToInv.Click += new System.EventHandler(this.buttonAddNewToInv_Click);
            // 
            // buttonRefresh
            // 
            this.buttonRefresh.Location = new System.Drawing.Point(342, 127);
            this.buttonRefresh.Name = "buttonRefresh";
            this.buttonRefresh.Size = new System.Drawing.Size(137, 23);
            this.buttonRefresh.TabIndex = 16;
            this.buttonRefresh.Text = "Refresh";
            this.buttonRefresh.UseVisualStyleBackColor = true;
            this.buttonRefresh.Click += new System.EventHandler(this.buttonRefresh_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonAddShipping);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.numericCost);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.comboBoxShippingType);
            this.groupBox1.Location = new System.Drawing.Point(1021, 51);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 100);
            this.groupBox1.TabIndex = 15;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "International Shipping";
            // 
            // buttonAddShipping
            // 
            this.buttonAddShipping.Location = new System.Drawing.Point(65, 72);
            this.buttonAddShipping.Name = "buttonAddShipping";
            this.buttonAddShipping.Size = new System.Drawing.Size(75, 23);
            this.buttonAddShipping.TabIndex = 34;
            this.buttonAddShipping.Text = "Add";
            this.buttonAddShipping.UseVisualStyleBackColor = true;
            this.buttonAddShipping.Click += new System.EventHandler(this.buttonAddShipping_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(165, 48);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(30, 13);
            this.label11.TabIndex = 33;
            this.label11.Text = "USD";
            // 
            // numericCost
            // 
            this.numericCost.DecimalPlaces = 2;
            this.numericCost.Location = new System.Drawing.Point(43, 46);
            this.numericCost.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericCost.Minimum = new decimal(new int[] {
            276447232,
            23283,
            0,
            -2147483648});
            this.numericCost.Name = "numericCost";
            this.numericCost.Size = new System.Drawing.Size(116, 20);
            this.numericCost.TabIndex = 32;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(28, 13);
            this.label6.TabIndex = 2;
            this.label6.Text = "Cost";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(31, 13);
            this.label4.TabIndex = 1;
            this.label4.Text = "Type";
            // 
            // comboBoxShippingType
            // 
            this.comboBoxShippingType.FormattingEnabled = true;
            this.comboBoxShippingType.Items.AddRange(new object[] {
            "iHerb",
            "USPS",
            "Chengyue",
            "Other"});
            this.comboBoxShippingType.Location = new System.Drawing.Point(43, 19);
            this.comboBoxShippingType.Name = "comboBoxShippingType";
            this.comboBoxShippingType.Size = new System.Drawing.Size(151, 21);
            this.comboBoxShippingType.TabIndex = 0;
            this.comboBoxShippingType.Text = "iHerb";
            // 
            // buttonUpdateSum
            // 
            this.buttonUpdateSum.Location = new System.Drawing.Point(609, 58);
            this.buttonUpdateSum.Name = "buttonUpdateSum";
            this.buttonUpdateSum.Size = new System.Drawing.Size(75, 23);
            this.buttonUpdateSum.TabIndex = 14;
            this.buttonUpdateSum.Text = "Update Sum";
            this.buttonUpdateSum.UseVisualStyleBackColor = true;
            this.buttonUpdateSum.Visible = false;
            this.buttonUpdateSum.Click += new System.EventHandler(this.buttonUpdateSum_Click);
            // 
            // dataGridViewSum
            // 
            this.dataGridViewSum.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewSum.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewSum.ColumnHeadersVisible = false;
            this.dataGridViewSum.Location = new System.Drawing.Point(0, 3);
            this.dataGridViewSum.Name = "dataGridViewSum";
            this.dataGridViewSum.ScrollBars = System.Windows.Forms.ScrollBars.None;
            this.dataGridViewSum.Size = new System.Drawing.Size(1242, 25);
            this.dataGridViewSum.TabIndex = 7;
            // 
            // labelItemsSold
            // 
            this.labelItemsSold.AutoSize = true;
            this.labelItemsSold.Location = new System.Drawing.Point(79, 93);
            this.labelItemsSold.Name = "labelItemsSold";
            this.labelItemsSold.Size = new System.Drawing.Size(13, 13);
            this.labelItemsSold.TabIndex = 13;
            this.labelItemsSold.Text = "0";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(17, 93);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 13);
            this.label5.TabIndex = 12;
            this.label5.Text = "Items Sold";
            // 
            // labelProfit
            // 
            this.labelProfit.AutoSize = true;
            this.labelProfit.Location = new System.Drawing.Point(55, 70);
            this.labelProfit.Name = "labelProfit";
            this.labelProfit.Size = new System.Drawing.Size(13, 13);
            this.labelProfit.TabIndex = 11;
            this.labelProfit.Text = "0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 70);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "Profit";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(184, 45);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(20, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "To";
            // 
            // dateTimePickerTo
            // 
            this.dateTimePickerTo.CustomFormat = "MM/dd/yyyy";
            this.dateTimePickerTo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePickerTo.Location = new System.Drawing.Point(212, 43);
            this.dateTimePickerTo.Name = "dateTimePickerTo";
            this.dateTimePickerTo.Size = new System.Drawing.Size(114, 20);
            this.dateTimePickerTo.TabIndex = 8;
            this.dateTimePickerTo.ValueChanged += new System.EventHandler(this.dateTimePicker_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 45);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(30, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "From";
            // 
            // dateTimePickerFrom
            // 
            this.dateTimePickerFrom.CustomFormat = "MM/dd/yyyy";
            this.dateTimePickerFrom.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePickerFrom.Location = new System.Drawing.Point(58, 43);
            this.dateTimePickerFrom.Name = "dateTimePickerFrom";
            this.dateTimePickerFrom.Size = new System.Drawing.Size(114, 20);
            this.dateTimePickerFrom.TabIndex = 6;
            this.dateTimePickerFrom.ValueChanged += new System.EventHandler(this.dateTimePicker_ValueChanged);
            // 
            // SellHistoryForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1242, 482);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "SellHistoryForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "SellHistoryForm";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.SellHistoryForm_FormClosing);
            this.Load += new System.EventHandler(this.SellHistoryForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericCost)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSum)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.DateTimePicker dateTimePickerFrom;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DateTimePicker dateTimePickerTo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelProfit;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelItemsSold;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.DataGridView dataGridViewSum;
        private System.Windows.Forms.Button buttonUpdateSum;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox comboBoxShippingType;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button buttonAddShipping;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.NumericUpDown numericCost;
        private System.Windows.Forms.Button buttonRefresh;
        private System.Windows.Forms.Button buttonUpdateLocation;
        private System.Windows.Forms.Button buttonSell;
        private System.Windows.Forms.Button buttonAddNewToInv;
        private System.Windows.Forms.Button buttonChart;
    }
}