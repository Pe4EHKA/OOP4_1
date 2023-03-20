#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class CCircle {
private:
	double m_x;  // ���������� x ������ �����
	double m_y;  // ���������� y ������ �����
	double m_radius;  // ������ �����
	bool m_selected;  // ������� �������� �����������, �������� �� ���� ����������
public:
	CCircle(double x, double y, double radius) : m_x(x), m_y(y), m_radius(radius), m_selected(false) {}  // ����������� � �����������

	double GetRadius() {
		return m_radius;
	}

	double const GetX() {
		return m_x;
	}

	double const GetY() {
		return m_y;
	}

	bool const isSelected() {
		return m_selected;
	}

	void Select() {
		m_selected = true;
	}

	void Deselect() {
		m_selected = false;
	}

	void SetSelected(bool set) {
		m_selected = set;
	}

	void SetPosition(double x, double y) {  // ���������� ������� ������ �����
		m_x = x;
		m_y = y;
	}

	void SetRadius(double radius) {  // ���������� ������ �����
		m_radius = radius;
	}


	bool IsPointInside(double x, double y) {  // ����� ��� ��������, ��������� �� ����� ������ �����
		double distance = (x - m_x) * (x - m_x) + (y - m_y) * (y - m_y);
		return distance <= m_radius * m_radius;
	}

	void Draw(Graphics^ graphics) {
		if (m_selected) {
			// ���� ���� ����������, ������ ��� � ������ �������� � ��������
			SolidBrush^ brush = gcnew SolidBrush(Color::Red);
			Pen^ pen = gcnew Pen(Color::Green, 2);
			graphics->FillEllipse(brush, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
			graphics->DrawEllipse(pen, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
		}
		else {
			// ���� ���� �� ����������, ������ ��� � ������� �������� � ��������
			SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
			Pen^ pen = gcnew Pen(Color::Black, 1);
			graphics->FillEllipse(brush, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
			graphics->DrawEllipse(pen, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
		}
	}
};