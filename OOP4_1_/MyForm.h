#pragma once
#include "CCircle.h"

namespace OOP41 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			m_circles = gcnew Generic::List<CCircle^>();
			m_selectedCircles = gcnew Generic::List<CCircle^>();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ PaintBox;
	protected:

	protected:
		Generic::List<CCircle^>^ m_circles;  // ��������� ��� �������� �������� CCircle
		Generic::List<CCircle^>^ m_selectedCircles;  // ��������� ��� �������� ���������� �������� CCircle
		CCircle^ selectedCircle = nullptr; // ��������� �� ��������� ������ CCircle
		bool ctrlPressed = false;  // ���� ������� ������� Ctrl
		bool setMultiple = false;  // ���� ��� ��������� ���������� ������
		bool ctrl_change = false;  // ���� �������� ������� Ctrl

	private: System::Windows::Forms::CheckBox^ ctrlCheckBox;
	protected:
	private: System::Windows::Forms::Button^ DelButton;


	private: System::Windows::Forms::CheckBox^ multiSelectCheckBox;	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->PaintBox = (gcnew System::Windows::Forms::PictureBox());
			this->ctrlCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->multiSelectCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->DelButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaintBox))->BeginInit();
			this->SuspendLayout();
			// 
			// PaintBox
			// 
			this->PaintBox->Location = System::Drawing::Point(12, 95);
			this->PaintBox->Name = L"PaintBox";
			this->PaintBox->Size = System::Drawing::Size(1492, 846);
			this->PaintBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->PaintBox->TabIndex = 0;
			this->PaintBox->TabStop = false;
			this->PaintBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::PaintBox_Paint);
			this->PaintBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PaintBox_MouseDown);
			this->PaintBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PaintBox_MouseMove);
			// 
			// ctrlCheckBox
			// 
			this->ctrlCheckBox->AutoSize = true;
			this->ctrlCheckBox->Location = System::Drawing::Point(56, 54);
			this->ctrlCheckBox->Name = L"ctrlCheckBox";
			this->ctrlCheckBox->Size = System::Drawing::Size(77, 29);
			this->ctrlCheckBox->TabIndex = 1;
			this->ctrlCheckBox->Text = L"Ctrl";
			this->ctrlCheckBox->UseVisualStyleBackColor = true;
			this->ctrlCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ctrlCheckBox_CheckedChanged);
			this->ctrlCheckBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ctrlCheckBox_KeyDown);
			this->ctrlCheckBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ctrlCheckBox_KeyUp);
			// 
			// multiSelectCheckBox
			// 
			this->multiSelectCheckBox->AutoSize = true;
			this->multiSelectCheckBox->Location = System::Drawing::Point(255, 54);
			this->multiSelectCheckBox->Name = L"multiSelectCheckBox";
			this->multiSelectCheckBox->Size = System::Drawing::Size(276, 29);
			this->multiSelectCheckBox->TabIndex = 2;
			this->multiSelectCheckBox->Text = L"������������� �����";
			this->multiSelectCheckBox->UseVisualStyleBackColor = true;
			this->multiSelectCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::multiSelectCheckBox_CheckedChanged);
			// 
			// DelButton
			// 
			this->DelButton->Location = System::Drawing::Point(630, 40);
			this->DelButton->Name = L"DelButton";
			this->DelButton->Size = System::Drawing::Size(131, 55);
			this->DelButton->TabIndex = 3;
			this->DelButton->Text = L"Del";
			this->DelButton->UseVisualStyleBackColor = true;
			this->DelButton->Click += gcnew System::EventHandler(this, &MyForm::DelButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1518, 953);
			this->Controls->Add(this->PaintBox);
			this->Controls->Add(this->DelButton);
			this->Controls->Add(this->ctrlCheckBox);
			this->Controls->Add(this->multiSelectCheckBox);
			this->Name = L"MyForm";
			this->Text = L"GUI C++/CLI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PaintBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ���������� ������� Paint ��� PaintBox
	private: System::Void PaintBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// ������������ ��� ������� CCircle �� PaintBox
		for each (CCircle ^ circle in m_circles) {
			circle->Draw(e->Graphics);
		}
	}
	private: System::Void PaintBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			selectedCircle = nullptr;
			// ���� ����, � ������� ����� ���� ����
			for each (CCircle ^ circle in m_circles) {
				if (circle->IsPointInside(e->X, e->Y)) {
					selectedCircle = circle;
					break;
				}
			}
			if (selectedCircle != nullptr) {
				if (ctrlPressed) {
					// ���� ������ ������� Ctrl, �� ���������/������� ���� �� ������ ����������
					bool isSelected = selectedCircle->isSelected();
					selectedCircle->SetSelected(!isSelected);
					if (!isSelected) {
						m_selectedCircles->Add(selectedCircle);
					}
					else {
						m_selectedCircles->Remove(selectedCircle);
					}

				}
				else if (setMultiple) {
					// ���� ���� m_selectMultiple ����������, �� �������� ��� �����, � ������� ������ ����
					for each (CCircle ^ circle in m_circles) {
						if (circle->IsPointInside(e->X, e->Y)) {
							circle->SetSelected(true);
							m_selectedCircles->Add(circle);
						}
					}


				}
				else {
					// ����� ������� ��������� �� ���� ������ � �������� ������ �������
					for each (CCircle ^ circle in m_circles) {
						circle->SetSelected(false);
					}
					m_selectedCircles->Clear();
					selectedCircle->SetSelected(true);
					m_selectedCircles->Add(selectedCircle);
				}
			}
			else {
				// ���� ���� ��� ��� ������, �� ������� ��������� �� ���� ������
				for each (CCircle ^ circle in m_circles) {
					circle->SetSelected(false);
				}
				m_selectedCircles->Clear();
				// � ������� �����
				CCircle^ circle = gcnew CCircle(e->X, e->Y, 50);
				m_circles->Add(circle);
				circle->SetSelected(true);
				m_selectedCircles->Add(circle);
			}
			PaintBox->Invalidate();
		}

	}
	private: System::Void PaintBox_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		bool found = false;
		for each (CCircle ^ circle in m_circles) {
			if (circle->IsPointInside(e->X, e->Y)) {
				found = true;
				break;
			}
		}
		if (found) {
			this->Cursor = Cursors::Hand;
		}
		else {
			this->Cursor = Cursors::Default;
		}
	}
	private: System::Void ctrlCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ctrlPressed = ctrlCheckBox->Checked;
		ctrlCheckBox->Select();

	}
	private: System::Void multiSelectCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		setMultiple = multiSelectCheckBox->Checked;
		ctrlCheckBox->Select();
	}

	private: System::Void DelButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// ������� ��������� ������ ��� �������� ������, ������� �� ����� �������
		Generic::List<CCircle^>^ tempCircles = gcnew Generic::List<CCircle^>;
		// ���������� �� ������ ������ � ��������� �� ��������� ������ ��, ������� �� ��������
		for each (CCircle ^ circle in m_circles) {
			if (!circle->isSelected()) {
				tempCircles->Add(circle);
			}
		}
		// ������� ������ ������ � ��������� � ���� ������ ��, ������� �� ����� �������
		m_circles->Clear();
		m_circles->AddRange(tempCircles);

		// �������������� ������� ��� ���������
		selectedCircle = nullptr;
		PaintBox->Invalidate();
		ctrlCheckBox->Select();

	}

	private: System::Void ctrlCheckBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			Generic::List<CCircle^>^ tempCircles = gcnew Generic::List<CCircle^>;
			// ���������� �� ������ ������ � ��������� �� ��������� ������ ��, ������� �� ��������
			for each (CCircle ^ circle in m_circles) {
				if (!circle->isSelected()) {
					tempCircles->Add(circle);
				}
			}
			// ������� ������ ������ � ��������� � ���� ������ ��, ������� �� ����� �������
			m_circles->Clear();
			m_circles->AddRange(tempCircles);

			// �������������� ������� ��� ���������
			selectedCircle = nullptr;
			PaintBox->Invalidate();
		}
		else if (e->KeyCode == Keys::ControlKey) {
			if (!ctrlPressed) {
				ctrlPressed = true;
				ctrlCheckBox->Checked = true;
				ctrl_change = false;
			}
			else if (ctrl_change) {
				ctrlPressed = false;
				ctrlCheckBox->Checked = false;
			}
		}
	}
	private: System::Void ctrlCheckBox_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		ctrl_change = true;
		ctrlPressed = false;
		ctrlCheckBox->Checked = false;
	}
	};
}
