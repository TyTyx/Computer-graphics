#pragma once

#include "OpenGL_WinApp.h"
#include <glm.hpp>  // Maths library
#include <../gtc/matrix_transform.hpp>

namespace OpenGL_3D2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace OpenGLForm;  //#1

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
		private: OpenGLForm::Create_OpenGL ^OpenGL; // #2 pointer to OpenGL
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			// Create an OpenGL frame on the form (xpos,yos,width,height)
			OpenGL = gcnew Create_OpenGL(this, 10, 10, 640, 480); // #3 

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(24, 520);
			this->trackBar1->Maximum = 180;
			this->trackBar1->Minimum = -180;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(600, 45);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &Form1::trackBar1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(630, 520);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(680, 20);
			this->trackBar2->Maximum = 50;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar2->Size = System::Drawing::Size(45, 280);
			this->trackBar2->TabIndex = 2;
			this->trackBar2->Value = 10;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(677, 303);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(750, 20);
			this->trackBar3->Maximum = 180;
			this->trackBar3->Minimum = -180;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar3->Size = System::Drawing::Size(45, 280);
			this->trackBar3->TabIndex = 4;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &Form1::trackBar3_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(747, 303);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(726, 384);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(726, 478);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 16);
			this->label5->TabIndex = 7;
			this->label5->Text = L"label5";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 601);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->trackBar3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 // OpenGL->longitude+=0.025;
				 OpenGL->Render();
				 glm::mat4 p;

			// Display projection matrix
			glGetFloatv(GL_PROJECTION_MATRIX,&p[0][0]);
 
			label4->Text = "PROJECTION_MATRIX: \n"+"("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";

		// Display model matrix
		glGetFloatv(GL_MODELVIEW_MATRIX,&p[0][0]); 

		label5->Text = "MODELVIEW_MATRIX: \n"+"("+String::Format("{0:0.00}",p[0][0])+","+String::Format("{0:0.00}",p[1][0])+","+String::Format("{0:0.00}",p[2][0])+","+String::Format("{0:0.00}",p[3][0])+")\n"+
				             "("+String::Format("{0:0.00}",p[0][1])+","+String::Format("{0:0.00}",p[1][1])+","+String::Format("{0:0.00}",p[2][1])+","+String::Format("{0:0.00}",p[3][1])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][2])+","+String::Format("{0:0.00}",p[1][2])+","+String::Format("{0:0.00}",p[2][2])+","+String::Format("{0:0.00}",p[3][2])+")\n"+
							 "("+String::Format("{0:0.00}",p[0][3])+","+String::Format("{0:0.00}",p[1][3])+","+String::Format("{0:0.00}",p[2][3])+","+String::Format("{0:0.00}",p[3][3])+")";

			 }
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->longitude=(90+trackBar1->Value) * M_PI/180.0;
				 // Dodge to move focus on from trackbar (also displays value)
				 label1->Text = "Longitude: "+System::Convert::ToString(trackBar1->Value);

			 }
	private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->radius=(trackBar2->Value);
				label2->Text = "Radius: "+System::Convert::ToString(trackBar2->Value);

			 }
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 OpenGL->latitude=(trackBar3->Value)*M_PI/180.0;
			label3->Text = "Latitude: "+System::Convert::ToString(trackBar3->Value) ;

		 }
};
}

