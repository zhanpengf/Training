using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BusinessManager
{
    public partial class AddNewSellForm : Form
    {
        // a pointer to the sell history form
        public SellHistoryForm sellHistoryForm;

        public string products;
        public float cost;
        public int quantity;
        public float profit;
        public string notes;
        public DateTime sellingDate;
        public float sellingPrice;
        public float internationalShipping;
        public float domesticShipping;
        public float customerPaidShipping;
        public float exRate;
        public bool addToExist;
        public int chosenID; 

        public AddNewSellForm()
        {
            InitializeComponent();            
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            products = textBoxProducts.Text;
            cost = (float)numericCost.Value;
            quantity = (int)numericQuantity.Value;
            sellingDate = dateTimePickerSellingDate.Value;
            cost = (float)numericCost.Value;
            sellingPrice = (float)numericSellingPrice.Value;
            internationalShipping = (float)numericInternationalShipping.Value;
            domesticShipping = (float)numericDomesticShipping.Value;
            customerPaidShipping = (float)numericCustomerPaidShipping.Value;
            profit = sellingPrice + customerPaidShipping - cost * exRate
                - internationalShipping * exRate - domesticShipping;
            notes = textBoxNotes.Text;
            DialogResult = System.Windows.Forms.DialogResult.OK;
            Close();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = System.Windows.Forms.DialogResult.Cancel;
            Close();
        }

        private void AddNewSellForm_Load(object sender, EventArgs e)
        {
            textBoxProducts.Text = products;
            numericQuantity.Value = quantity;
            numericCost.Value = Convert.ToDecimal(cost);
            checkBoxAddToExist.Checked = false;
        }

        private void AnyCost_ValueChanged(object sender, EventArgs e)
        {
            cost = (float)numericCost.Value;
            sellingPrice = (float)numericSellingPrice.Value;
            internationalShipping = (float)numericInternationalShipping.Value;
            domesticShipping = (float)numericDomesticShipping.Value;
            customerPaidShipping= (float)numericCustomerPaidShipping.Value;
            profit = sellingPrice + customerPaidShipping - cost * exRate
                - internationalShipping * exRate - domesticShipping;
            textBoxProfit.Text = profit.ToString();
            
        }

        private void checkBoxAddToExist_CheckedChanged(object sender, EventArgs e)
        {
            addToExist = false;
            if (checkBoxAddToExist.Checked)
            {                
                sellHistoryForm.formType = SellHistFormType.ChooseExisting;
                sellHistoryForm.ShowDialog();
                if (sellHistoryForm.ChosenID != -1)
                {
                    chosenID = sellHistoryForm.ChosenID;
                    addToExist = true;
                }
                else
                {
                    MessageBox.Show("Invalid sell history item is chosen. \n\rFail to add. ", "Error", MessageBoxButtons.OK,
                                MessageBoxIcon.Error);
                    checkBoxAddToExist.Checked = false; 
                }
            }
        }

        private void AddNewSellForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //this.Hide();
            //e.Cancel = true; // this cancels the close event.
        }
    }
}
