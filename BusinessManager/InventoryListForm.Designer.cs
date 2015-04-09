namespace BusinessManager
{
    partial class InventoryListForm
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.ColumnCheck = new System.Windows.Forms.DataGridViewCheckBoxColumn();
            this.ColumnSellCount = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ColumnNewLocation = new System.Windows.Forms.DataGridViewComboBoxColumn();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonNext = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonShowAll = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonApplySQL = new System.Windows.Forms.Button();
            this.textBoxSQL = new System.Windows.Forms.TextBox();
            this.dataGridViewSum = new System.Windows.Forms.DataGridView();
            this.checkBoxHighlight = new System.Windows.Forms.CheckBox();
            this.buttonUpdateLocation = new System.Windows.Forms.Button();
            this.buttonShowSellHistory = new System.Windows.Forms.Button();
            this.buttonSell = new System.Windows.Forms.Button();
            this.buttonAddNewToInv = new System.Windows.Forms.Button();
            this.checkBoxSelectAll = new System.Windows.Forms.CheckBox();
            this.groupBoxLocation = new System.Windows.Forms.GroupBox();
            this.radioButtonShippingInUS = new System.Windows.Forms.RadioButton();
            this.radioButtonTransitAndTaiwan = new System.Windows.Forms.RadioButton();
            this.radioButtonAllLocation = new System.Windows.Forms.RadioButton();
            this.radioButtonInTransit = new System.Windows.Forms.RadioButton();
            this.radioButtonTaiwan = new System.Windows.Forms.RadioButton();
            this.radioButtonUSA = new System.Windows.Forms.RadioButton();
            this.buttonUpdate = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSum)).BeginInit();
            this.groupBoxLocation.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ColumnCheck,
            this.ColumnSellCount,
            this.ColumnNewLocation});
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(1242, 336);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);
            this.dataGridView1.ColumnWidthChanged += new System.Windows.Forms.DataGridViewColumnEventHandler(this.dataGridView1_ColumnWidthChanged);
            this.dataGridView1.CurrentCellDirtyStateChanged += new System.EventHandler(this.dataGridView1_CurrentCellDirtyStateChanged);
            this.dataGridView1.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.dataGridView1_DataError);
            this.dataGridView1.RowsAdded += new System.Windows.Forms.DataGridViewRowsAddedEventHandler(this.dataGridView1_RowsAdded);
            this.dataGridView1.RowsRemoved += new System.Windows.Forms.DataGridViewRowsRemovedEventHandler(this.dataGridView1_RowsRemoved);
            this.dataGridView1.Sorted += new System.EventHandler(this.dataGridView1_Sorted);
            // 
            // ColumnCheck
            // 
            this.ColumnCheck.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.ColumnCheck.HeaderText = "Select";
            this.ColumnCheck.Name = "ColumnCheck";
            this.ColumnCheck.Width = 43;
            // 
            // ColumnSellCount
            // 
            this.ColumnSellCount.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.ColumnSellCount.HeaderText = "Sell Quantity";
            this.ColumnSellCount.Name = "ColumnSellCount";
            this.ColumnSellCount.Width = 91;
            // 
            // ColumnNewLocation
            // 
            this.ColumnNewLocation.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.None;
            this.ColumnNewLocation.HeaderText = "New Location";
            this.ColumnNewLocation.Items.AddRange(new object[] {
            "USA",
            "Taiwan",
            "In Transit",
            "Shipping in US"});
            this.ColumnNewLocation.Name = "ColumnNewLocation";
            this.ColumnNewLocation.Width = 79;
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(642, 203);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(75, 23);
            this.buttonSave.TabIndex = 1;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // buttonNext
            // 
            this.buttonNext.Location = new System.Drawing.Point(534, 203);
            this.buttonNext.Name = "buttonNext";
            this.buttonNext.Size = new System.Drawing.Size(75, 23);
            this.buttonNext.TabIndex = 2;
            this.buttonNext.Text = "Next";
            this.buttonNext.UseVisualStyleBackColor = true;
            this.buttonNext.Click += new System.EventHandler(this.buttonNext_Click);
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.Controls.Add(this.buttonShowAll);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.buttonApplySQL);
            this.panel1.Controls.Add(this.textBoxSQL);
            this.panel1.Controls.Add(this.dataGridViewSum);
            this.panel1.Controls.Add(this.checkBoxHighlight);
            this.panel1.Controls.Add(this.buttonUpdateLocation);
            this.panel1.Controls.Add(this.buttonShowSellHistory);
            this.panel1.Controls.Add(this.buttonSell);
            this.panel1.Controls.Add(this.buttonAddNewToInv);
            this.panel1.Controls.Add(this.checkBoxSelectAll);
            this.panel1.Controls.Add(this.groupBoxLocation);
            this.panel1.Controls.Add(this.buttonUpdate);
            this.panel1.Controls.Add(this.buttonSave);
            this.panel1.Controls.Add(this.buttonNext);
            this.panel1.Location = new System.Drawing.Point(0, 339);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1242, 269);
            this.panel1.TabIndex = 3;
            // 
            // buttonShowAll
            // 
            this.buttonShowAll.Location = new System.Drawing.Point(847, 77);
            this.buttonShowAll.Name = "buttonShowAll";
            this.buttonShowAll.Size = new System.Drawing.Size(75, 23);
            this.buttonShowAll.TabIndex = 17;
            this.buttonShowAll.Text = "All";
            this.buttonShowAll.UseVisualStyleBackColor = true;
            this.buttonShowAll.Click += new System.EventHandler(this.buttonShowAll_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(356, 46);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(28, 13);
            this.label1.TabIndex = 16;
            this.label1.Text = "SQL";
            // 
            // buttonApplySQL
            // 
            this.buttonApplySQL.Location = new System.Drawing.Point(847, 48);
            this.buttonApplySQL.Name = "buttonApplySQL";
            this.buttonApplySQL.Size = new System.Drawing.Size(75, 23);
            this.buttonApplySQL.TabIndex = 15;
            this.buttonApplySQL.Text = "Apply";
            this.buttonApplySQL.UseVisualStyleBackColor = true;
            this.buttonApplySQL.Click += new System.EventHandler(this.buttonApplySQL_Click);
            // 
            // textBoxSQL
            // 
            this.textBoxSQL.Location = new System.Drawing.Point(397, 46);
            this.textBoxSQL.Multiline = true;
            this.textBoxSQL.Name = "textBoxSQL";
            this.textBoxSQL.Size = new System.Drawing.Size(444, 83);
            this.textBoxSQL.TabIndex = 14;
            this.textBoxSQL.Text = "SELECT * FROM Inventory where [Current Location] like \'Taiwan\' and [Product Name]" +
                " like \'%Sanuk Donna%\' ";
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
            this.dataGridViewSum.TabIndex = 13;
            // 
            // checkBoxHighlight
            // 
            this.checkBoxHighlight.AutoSize = true;
            this.checkBoxHighlight.Checked = true;
            this.checkBoxHighlight.CheckState = System.Windows.Forms.CheckState.Checked;
            this.checkBoxHighlight.Location = new System.Drawing.Point(271, 44);
            this.checkBoxHighlight.Name = "checkBoxHighlight";
            this.checkBoxHighlight.Size = new System.Drawing.Size(67, 17);
            this.checkBoxHighlight.TabIndex = 12;
            this.checkBoxHighlight.Text = "Highlight";
            this.checkBoxHighlight.UseVisualStyleBackColor = true;
            this.checkBoxHighlight.CheckedChanged += new System.EventHandler(this.checkBoxHighlight_CheckedChanged);
            // 
            // buttonUpdateLocation
            // 
            this.buttonUpdateLocation.Location = new System.Drawing.Point(195, 134);
            this.buttonUpdateLocation.Name = "buttonUpdateLocation";
            this.buttonUpdateLocation.Size = new System.Drawing.Size(137, 23);
            this.buttonUpdateLocation.TabIndex = 11;
            this.buttonUpdateLocation.Text = "Update Location";
            this.buttonUpdateLocation.UseVisualStyleBackColor = true;
            this.buttonUpdateLocation.Click += new System.EventHandler(this.buttonUpdateLocation_Click_1);
            // 
            // buttonShowSellHistory
            // 
            this.buttonShowSellHistory.Location = new System.Drawing.Point(195, 163);
            this.buttonShowSellHistory.Name = "buttonShowSellHistory";
            this.buttonShowSellHistory.Size = new System.Drawing.Size(137, 23);
            this.buttonShowSellHistory.TabIndex = 10;
            this.buttonShowSellHistory.Text = "Show Sell History";
            this.buttonShowSellHistory.UseVisualStyleBackColor = true;
            this.buttonShowSellHistory.Click += new System.EventHandler(this.buttonShowSellHistory_Click);
            // 
            // buttonSell
            // 
            this.buttonSell.Location = new System.Drawing.Point(195, 106);
            this.buttonSell.Name = "buttonSell";
            this.buttonSell.Size = new System.Drawing.Size(137, 23);
            this.buttonSell.TabIndex = 9;
            this.buttonSell.Text = "Sell";
            this.buttonSell.UseVisualStyleBackColor = true;
            this.buttonSell.Click += new System.EventHandler(this.buttonSell_Click);
            // 
            // buttonAddNewToInv
            // 
            this.buttonAddNewToInv.Location = new System.Drawing.Point(195, 77);
            this.buttonAddNewToInv.Name = "buttonAddNewToInv";
            this.buttonAddNewToInv.Size = new System.Drawing.Size(137, 23);
            this.buttonAddNewToInv.TabIndex = 8;
            this.buttonAddNewToInv.Text = "Add New to Inventory";
            this.buttonAddNewToInv.UseVisualStyleBackColor = true;
            this.buttonAddNewToInv.Click += new System.EventHandler(this.buttonAddNewToInv_Click);
            // 
            // checkBoxSelectAll
            // 
            this.checkBoxSelectAll.AutoSize = true;
            this.checkBoxSelectAll.Location = new System.Drawing.Point(195, 44);
            this.checkBoxSelectAll.Name = "checkBoxSelectAll";
            this.checkBoxSelectAll.Size = new System.Drawing.Size(70, 17);
            this.checkBoxSelectAll.TabIndex = 5;
            this.checkBoxSelectAll.Text = "Select All";
            this.checkBoxSelectAll.UseVisualStyleBackColor = true;
            this.checkBoxSelectAll.CheckedChanged += new System.EventHandler(this.checkBoxSelectAll_CheckedChanged);
            // 
            // groupBoxLocation
            // 
            this.groupBoxLocation.Controls.Add(this.radioButtonShippingInUS);
            this.groupBoxLocation.Controls.Add(this.radioButtonTransitAndTaiwan);
            this.groupBoxLocation.Controls.Add(this.radioButtonAllLocation);
            this.groupBoxLocation.Controls.Add(this.radioButtonInTransit);
            this.groupBoxLocation.Controls.Add(this.radioButtonTaiwan);
            this.groupBoxLocation.Controls.Add(this.radioButtonUSA);
            this.groupBoxLocation.Location = new System.Drawing.Point(21, 35);
            this.groupBoxLocation.Name = "groupBoxLocation";
            this.groupBoxLocation.Size = new System.Drawing.Size(151, 164);
            this.groupBoxLocation.TabIndex = 4;
            this.groupBoxLocation.TabStop = false;
            this.groupBoxLocation.Text = "Location";
            // 
            // radioButtonShippingInUS
            // 
            this.radioButtonShippingInUS.AutoSize = true;
            this.radioButtonShippingInUS.Location = new System.Drawing.Point(6, 111);
            this.radioButtonShippingInUS.Name = "radioButtonShippingInUS";
            this.radioButtonShippingInUS.Size = new System.Drawing.Size(95, 17);
            this.radioButtonShippingInUS.TabIndex = 5;
            this.radioButtonShippingInUS.Text = "Shipping in US";
            this.radioButtonShippingInUS.UseVisualStyleBackColor = true;
            this.radioButtonShippingInUS.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // radioButtonTransitAndTaiwan
            // 
            this.radioButtonTransitAndTaiwan.AutoSize = true;
            this.radioButtonTransitAndTaiwan.Location = new System.Drawing.Point(6, 88);
            this.radioButtonTransitAndTaiwan.Name = "radioButtonTransitAndTaiwan";
            this.radioButtonTransitAndTaiwan.Size = new System.Drawing.Size(116, 17);
            this.radioButtonTransitAndTaiwan.TabIndex = 4;
            this.radioButtonTransitAndTaiwan.Text = "In Transit + Taiwan";
            this.radioButtonTransitAndTaiwan.UseVisualStyleBackColor = true;
            this.radioButtonTransitAndTaiwan.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // radioButtonAllLocation
            // 
            this.radioButtonAllLocation.AutoSize = true;
            this.radioButtonAllLocation.Checked = true;
            this.radioButtonAllLocation.Location = new System.Drawing.Point(6, 134);
            this.radioButtonAllLocation.Name = "radioButtonAllLocation";
            this.radioButtonAllLocation.Size = new System.Drawing.Size(36, 17);
            this.radioButtonAllLocation.TabIndex = 3;
            this.radioButtonAllLocation.TabStop = true;
            this.radioButtonAllLocation.Text = "All";
            this.radioButtonAllLocation.UseVisualStyleBackColor = true;
            this.radioButtonAllLocation.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // radioButtonInTransit
            // 
            this.radioButtonInTransit.AutoSize = true;
            this.radioButtonInTransit.Location = new System.Drawing.Point(6, 65);
            this.radioButtonInTransit.Name = "radioButtonInTransit";
            this.radioButtonInTransit.Size = new System.Drawing.Size(69, 17);
            this.radioButtonInTransit.TabIndex = 2;
            this.radioButtonInTransit.Text = "In Transit";
            this.radioButtonInTransit.UseVisualStyleBackColor = true;
            this.radioButtonInTransit.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // radioButtonTaiwan
            // 
            this.radioButtonTaiwan.AutoSize = true;
            this.radioButtonTaiwan.Location = new System.Drawing.Point(6, 42);
            this.radioButtonTaiwan.Name = "radioButtonTaiwan";
            this.radioButtonTaiwan.Size = new System.Drawing.Size(60, 17);
            this.radioButtonTaiwan.TabIndex = 1;
            this.radioButtonTaiwan.Text = "Taiwan";
            this.radioButtonTaiwan.UseVisualStyleBackColor = true;
            this.radioButtonTaiwan.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // radioButtonUSA
            // 
            this.radioButtonUSA.AutoSize = true;
            this.radioButtonUSA.Location = new System.Drawing.Point(6, 19);
            this.radioButtonUSA.Name = "radioButtonUSA";
            this.radioButtonUSA.Size = new System.Drawing.Size(47, 17);
            this.radioButtonUSA.TabIndex = 0;
            this.radioButtonUSA.Text = "USA";
            this.radioButtonUSA.UseVisualStyleBackColor = true;
            this.radioButtonUSA.CheckedChanged += new System.EventHandler(this.radioButtonLocation_CheckedChanged);
            // 
            // buttonUpdate
            // 
            this.buttonUpdate.Location = new System.Drawing.Point(534, 203);
            this.buttonUpdate.Name = "buttonUpdate";
            this.buttonUpdate.Size = new System.Drawing.Size(75, 23);
            this.buttonUpdate.TabIndex = 3;
            this.buttonUpdate.Text = "Update";
            this.buttonUpdate.UseVisualStyleBackColor = true;
            this.buttonUpdate.Click += new System.EventHandler(this.buttonUpdateLocation_Click);
            // 
            // InventoryListForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1242, 586);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.dataGridView1);
            this.Name = "InventoryListForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Master List";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSum)).EndInit();
            this.groupBoxLocation.ResumeLayout(false);
            this.groupBoxLocation.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonNext;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonUpdate;
        private System.Windows.Forms.GroupBox groupBoxLocation;
        private System.Windows.Forms.RadioButton radioButtonAllLocation;
        private System.Windows.Forms.RadioButton radioButtonInTransit;
        private System.Windows.Forms.RadioButton radioButtonTaiwan;
        private System.Windows.Forms.RadioButton radioButtonUSA;
        private System.Windows.Forms.CheckBox checkBoxSelectAll;
        private System.Windows.Forms.RadioButton radioButtonTransitAndTaiwan;
        private System.Windows.Forms.RadioButton radioButtonShippingInUS;
        public System.Windows.Forms.Button buttonUpdateLocation;
        public System.Windows.Forms.Button buttonShowSellHistory;
        public System.Windows.Forms.Button buttonSell;
        public System.Windows.Forms.Button buttonAddNewToInv;
        private System.Windows.Forms.CheckBox checkBoxHighlight;
        private System.Windows.Forms.DataGridView dataGridViewSum;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonApplySQL;
        private System.Windows.Forms.TextBox textBoxSQL;
        private System.Windows.Forms.DataGridViewCheckBoxColumn ColumnCheck;
        private System.Windows.Forms.DataGridViewTextBoxColumn ColumnSellCount;
        private System.Windows.Forms.DataGridViewComboBoxColumn ColumnNewLocation;
        private System.Windows.Forms.Button buttonShowAll;

    }
}

