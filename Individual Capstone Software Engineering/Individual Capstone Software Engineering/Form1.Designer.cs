namespace Individual_Capstone_Software_Engineering
{
    partial class Form1
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
            this.Basic = new System.Windows.Forms.Button();
            this.Ultra = new System.Windows.Forms.Button();
            this.Ultimate = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Basic
            // 
            this.Basic.Location = new System.Drawing.Point(32, 96);
            this.Basic.Name = "Basic";
            this.Basic.Size = new System.Drawing.Size(104, 42);
            this.Basic.TabIndex = 0;
            this.Basic.Text = "Basic ($5.00)";
            this.Basic.UseVisualStyleBackColor = true;
            this.Basic.Click += new System.EventHandler(this.Basic_Click);
            // 
            // Ultra
            // 
            this.Ultra.Location = new System.Drawing.Point(142, 96);
            this.Ultra.Name = "Ultra";
            this.Ultra.Size = new System.Drawing.Size(104, 42);
            this.Ultra.TabIndex = 1;
            this.Ultra.Text = "Ultra ($8.00)";
            this.Ultra.UseVisualStyleBackColor = true;
            this.Ultra.Click += new System.EventHandler(this.Ultra_Click);
            // 
            // Ultimate
            // 
            this.Ultimate.Location = new System.Drawing.Point(252, 96);
            this.Ultimate.Name = "Ultimate";
            this.Ultimate.Size = new System.Drawing.Size(104, 42);
            this.Ultimate.TabIndex = 2;
            this.Ultimate.Text = "Ultimate ($10.00)";
            this.Ultimate.UseVisualStyleBackColor = true;
            this.Ultimate.Click += new System.EventHandler(this.Ultimate_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(30, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(345, 37);
            this.label1.TabIndex = 3;
            this.label1.Text = "Choose your car wash:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(395, 173);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Ultimate);
            this.Controls.Add(this.Ultra);
            this.Controls.Add(this.Basic);
            this.Name = "Form1";
            this.Text = "Car Wash";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Basic;
        private System.Windows.Forms.Button Ultra;
        private System.Windows.Forms.Button Ultimate;
        private System.Windows.Forms.Label label1;
    }
}

