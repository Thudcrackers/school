namespace Car_Wash
{
    partial class selectWashForm
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
            this.label1 = new System.Windows.Forms.Label();
            this.standardRadio = new System.Windows.Forms.RadioButton();
            this.extraRadio = new System.Windows.Forms.RadioButton();
            this.deluxeRadio = new System.Windows.Forms.RadioButton();
            this.selectWashButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(60, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(125, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Select your desired level:";
            // 
            // standardRadio
            // 
            this.standardRadio.AutoSize = true;
            this.standardRadio.Location = new System.Drawing.Point(91, 37);
            this.standardRadio.Name = "standardRadio";
            this.standardRadio.Size = new System.Drawing.Size(51, 17);
            this.standardRadio.TabIndex = 1;
            this.standardRadio.TabStop = true;
            this.standardRadio.Text = "Basic";
            this.standardRadio.UseVisualStyleBackColor = true;
            // 
            // extraRadio
            // 
            this.extraRadio.AutoSize = true;
            this.extraRadio.Location = new System.Drawing.Point(91, 69);
            this.extraRadio.Name = "extraRadio";
            this.extraRadio.Size = new System.Drawing.Size(47, 17);
            this.extraRadio.TabIndex = 2;
            this.extraRadio.TabStop = true;
            this.extraRadio.Text = "Ultra";
            this.extraRadio.UseVisualStyleBackColor = true;
            // 
            // deluxeRadio
            // 
            this.deluxeRadio.AutoSize = true;
            this.deluxeRadio.Location = new System.Drawing.Point(91, 102);
            this.deluxeRadio.Name = "deluxeRadio";
            this.deluxeRadio.Size = new System.Drawing.Size(63, 17);
            this.deluxeRadio.TabIndex = 3;
            this.deluxeRadio.TabStop = true;
            this.deluxeRadio.Text = "Ultimate";
            this.deluxeRadio.UseVisualStyleBackColor = true;
            // 
            // selectWashButton
            // 
            this.selectWashButton.Location = new System.Drawing.Point(80, 140);
            this.selectWashButton.Name = "selectWashButton";
            this.selectWashButton.Size = new System.Drawing.Size(75, 23);
            this.selectWashButton.TabIndex = 5;
            this.selectWashButton.Text = "Next";
            this.selectWashButton.UseVisualStyleBackColor = true;
            this.selectWashButton.Click += new System.EventHandler(this.selectWashButton_Click);
            // 
            // selectWashForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(239, 210);
            this.Controls.Add(this.selectWashButton);
            this.Controls.Add(this.deluxeRadio);
            this.Controls.Add(this.extraRadio);
            this.Controls.Add(this.standardRadio);
            this.Controls.Add(this.label1);
            this.Name = "selectWashForm";
            this.Text = "selectWashForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RadioButton standardRadio;
        private System.Windows.Forms.RadioButton extraRadio;
        private System.Windows.Forms.RadioButton deluxeRadio;
        private System.Windows.Forms.Button selectWashButton;
    }
}