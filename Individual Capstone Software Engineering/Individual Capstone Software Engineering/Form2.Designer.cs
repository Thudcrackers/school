namespace Individual_Capstone_Software_Engineering
{
    partial class Form2
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
            this.Cash = new System.Windows.Forms.Button();
            this.Card = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Cash
            // 
            this.Cash.Location = new System.Drawing.Point(86, 99);
            this.Cash.Name = "Cash";
            this.Cash.Size = new System.Drawing.Size(104, 42);
            this.Cash.TabIndex = 1;
            this.Cash.Text = "Cash";
            this.Cash.UseVisualStyleBackColor = true;
            this.Cash.Click += new System.EventHandler(this.Cash_Click);
            // 
            // Card
            // 
            this.Card.Location = new System.Drawing.Point(86, 164);
            this.Card.Name = "Card";
            this.Card.Size = new System.Drawing.Size(104, 42);
            this.Card.TabIndex = 2;
            this.Card.Text = "Card";
            this.Card.UseVisualStyleBackColor = true;
            this.Card.Click += new System.EventHandler(this.Card_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F);
            this.label1.Location = new System.Drawing.Point(16, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(248, 26);
            this.label1.TabIndex = 3;
            this.label1.Text = "Select payment method:";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Card);
            this.Controls.Add(this.Cash);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Cash;
        private System.Windows.Forms.Button Card;
        private System.Windows.Forms.Label label1;
    }
}