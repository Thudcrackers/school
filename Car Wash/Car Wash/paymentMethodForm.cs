using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Car_Wash
{
    public partial class paymentMethodForm : Form
    {
        public paymentMethodForm(int washPrice, int washes)
        {
            InitializeComponent();

            int price = washPrice;
            int washNumber = washes;
            priceLabel.Text = price.ToString("C2");
            numberOfWashLabel.Text = washNumber.ToString();
        }

        private void cashButton_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Please insert cash.");
            System.Windows.Forms.Application.Exit();
        }

        private void cardButton_Click(object sender, EventArgs e)
        {
            cardForm card = new cardForm();
            this.Hide();
            card.Show();
        }
    }
}
