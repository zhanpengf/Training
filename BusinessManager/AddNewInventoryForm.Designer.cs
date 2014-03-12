namespace BusinessManager
{
    partial class AddNewInventoryForm
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
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.dateTimePickerExpDate = new System.Windows.Forms.DateTimePicker();
            this.dateTimePickerPurchasingDate = new System.Windows.Forms.DateTimePicker();
            this.dateTimePickerReturnDate = new System.Windows.Forms.DateTimePicker();
            this.numericQuantity = new System.Windows.Forms.NumericUpDown();
            this.textBoxNotes = new System.Windows.Forms.TextBox();
            this.textBoxPurchasingPlace = new System.Windows.Forms.TextBox();
            this.numericPurchasingPrice = new System.Windows.Forms.NumericUpDown();
            this.textBoxProductName = new System.Windows.Forms.TextBox();
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBoxCurrentLocation = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericQuantity)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericPurchasingPrice)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 14);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Product Name";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Purchasing Price";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Quantity";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 88);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(79, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Expiration Date";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 114);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(86, 13);
            this.label6.TabIndex = 5;
            this.label6.Text = "Purchasing Date";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 138);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(90, 13);
            this.label7.TabIndex = 6;
            this.label7.Text = "Purchasing Place";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(12, 162);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(65, 13);
            this.label8.TabIndex = 7;
            this.label8.Text = "Return Date";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(12, 210);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(35, 13);
            this.label9.TabIndex = 8;
            this.label9.Text = "Notes";
            // 
            // dateTimePickerExpDate
            // 
            this.dateTimePickerExpDate.CustomFormat = "MM dd, yy ";
            this.dateTimePickerExpDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerExpDate.Location = new System.Drawing.Point(123, 84);
            this.dateTimePickerExpDate.Name = "dateTimePickerExpDate";
            this.dateTimePickerExpDate.Size = new System.Drawing.Size(116, 20);
            this.dateTimePickerExpDate.TabIndex = 9;
            // 
            // dateTimePickerPurchasingDate
            // 
            this.dateTimePickerPurchasingDate.CustomFormat = "MM dd, yy ";
            this.dateTimePickerPurchasingDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerPurchasingDate.Location = new System.Drawing.Point(123, 107);
            this.dateTimePickerPurchasingDate.Name = "dateTimePickerPurchasingDate";
            this.dateTimePickerPurchasingDate.Size = new System.Drawing.Size(116, 20);
            this.dateTimePickerPurchasingDate.TabIndex = 1;
            // 
            // dateTimePickerReturnDate
            // 
            this.dateTimePickerReturnDate.Checked = false;
            this.dateTimePickerReturnDate.CustomFormat = "MM dd, yy ";
            this.dateTimePickerReturnDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerReturnDate.Location = new System.Drawing.Point(123, 158);
            this.dateTimePickerReturnDate.Name = "dateTimePickerReturnDate";
            this.dateTimePickerReturnDate.ShowCheckBox = true;
            this.dateTimePickerReturnDate.Size = new System.Drawing.Size(116, 20);
            this.dateTimePickerReturnDate.TabIndex = 11;
            this.dateTimePickerReturnDate.Value = new System.DateTime(2012, 9, 21, 0, 0, 0, 0);
            // 
            // numericQuantity
            // 
            this.numericQuantity.Location = new System.Drawing.Point(123, 60);
            this.numericQuantity.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericQuantity.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericQuantity.Name = "numericQuantity";
            this.numericQuantity.Size = new System.Drawing.Size(116, 20);
            this.numericQuantity.TabIndex = 12;
            this.numericQuantity.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // textBoxNotes
            // 
            this.textBoxNotes.Location = new System.Drawing.Point(123, 210);
            this.textBoxNotes.Multiline = true;
            this.textBoxNotes.Name = "textBoxNotes";
            this.textBoxNotes.Size = new System.Drawing.Size(186, 52);
            this.textBoxNotes.TabIndex = 13;
            // 
            // textBoxPurchasingPlace
            // 
            this.textBoxPurchasingPlace.Location = new System.Drawing.Point(123, 133);
            this.textBoxPurchasingPlace.Name = "textBoxPurchasingPlace";
            this.textBoxPurchasingPlace.Size = new System.Drawing.Size(186, 20);
            this.textBoxPurchasingPlace.TabIndex = 14;
            // 
            // numericPurchasingPrice
            // 
            this.numericPurchasingPrice.DecimalPlaces = 2;
            this.numericPurchasingPrice.Location = new System.Drawing.Point(123, 35);
            this.numericPurchasingPrice.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericPurchasingPrice.Name = "numericPurchasingPrice";
            this.numericPurchasingPrice.Size = new System.Drawing.Size(116, 20);
            this.numericPurchasingPrice.TabIndex = 15;
            // 
            // textBoxProductName
            // 
            this.textBoxProductName.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.SuggestAppend;
            this.textBoxProductName.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.CustomSource;
            this.textBoxProductName.Location = new System.Drawing.Point(123, 11);
            this.textBoxProductName.Name = "textBoxProductName";
            this.textBoxProductName.Size = new System.Drawing.Size(186, 20);
            this.textBoxProductName.TabIndex = 16;
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(72, 280);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(75, 23);
            this.buttonOK.TabIndex = 17;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCancel.Location = new System.Drawing.Point(164, 280);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(75, 23);
            this.buttonCancel.TabIndex = 18;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 188);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(85, 13);
            this.label1.TabIndex = 19;
            this.label1.Text = "Current Location";
            // 
            // comboBoxCurrentLocation
            // 
            this.comboBoxCurrentLocation.FormattingEnabled = true;
            this.comboBoxCurrentLocation.Items.AddRange(new object[] {
            "USA",
            "Taiwan",
            "In Transit",
            "Shipping in US"});
            this.comboBoxCurrentLocation.Location = new System.Drawing.Point(123, 183);
            this.comboBoxCurrentLocation.Name = "comboBoxCurrentLocation";
            this.comboBoxCurrentLocation.Size = new System.Drawing.Size(121, 21);
            this.comboBoxCurrentLocation.TabIndex = 20;
            this.comboBoxCurrentLocation.Text = "USA";
            // 
            // AddNewInventoryForm
            // 
            this.AcceptButton = this.buttonOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.buttonCancel;
            this.ClientSize = new System.Drawing.Size(348, 316);
            this.Controls.Add(this.comboBoxCurrentLocation);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.textBoxProductName);
            this.Controls.Add(this.numericPurchasingPrice);
            this.Controls.Add(this.textBoxPurchasingPlace);
            this.Controls.Add(this.textBoxNotes);
            this.Controls.Add(this.numericQuantity);
            this.Controls.Add(this.dateTimePickerReturnDate);
            this.Controls.Add(this.dateTimePickerExpDate);
            this.Controls.Add(this.dateTimePickerPurchasingDate);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Name = "AddNewInventoryForm";
            this.Text = "Add New";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.AddNewInventoryForm_FormClosing);
            this.Load += new System.EventHandler(this.AddNewInventoryForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericQuantity)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericPurchasingPrice)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.DateTimePicker dateTimePickerExpDate;
        private System.Windows.Forms.DateTimePicker dateTimePickerPurchasingDate;
        private System.Windows.Forms.DateTimePicker dateTimePickerReturnDate;
        private System.Windows.Forms.NumericUpDown numericQuantity;
        private System.Windows.Forms.TextBox textBoxNotes;
        private System.Windows.Forms.TextBox textBoxPurchasingPlace;
        private System.Windows.Forms.NumericUpDown numericPurchasingPrice;
        private System.Windows.Forms.TextBox textBoxProductName;
        private System.Windows.Forms.Button buttonOK;
        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBoxCurrentLocation;
        
        

    }
}