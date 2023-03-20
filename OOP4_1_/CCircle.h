#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref class CCircle {
private:
	double m_x;  // Координата x центра круга
	double m_y;  // Координата y центра круга
	double m_radius;  // Радиус круга
	bool m_selected;  // Булевое значение указывающее, является ли круг выделенным
public:
	CCircle(double x, double y, double radius) : m_x(x), m_y(y), m_radius(radius), m_selected(false) {}  // Конструктор с параметрами

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

	void SetPosition(double x, double y) {  // Установить позицию центра круга
		m_x = x;
		m_y = y;
	}

	void SetRadius(double radius) {  // Установить радиус круга
		m_radius = radius;
	}


	bool IsPointInside(double x, double y) {  // Метод для проверки, находится ли точка внутри круга
		double distance = (x - m_x) * (x - m_x) + (y - m_y) * (y - m_y);
		return distance <= m_radius * m_radius;
	}

	void Draw(Graphics^ graphics) {
		if (m_selected) {
			// Если круг выделенный, рисуем его с другой заливкой и обводкой
			SolidBrush^ brush = gcnew SolidBrush(Color::Red);
			Pen^ pen = gcnew Pen(Color::Green, 2);
			graphics->FillEllipse(brush, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
			graphics->DrawEllipse(pen, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
		}
		else {
			// если круг не выделенный, рисуем его с обычной заливкой и обводкой
			SolidBrush^ brush = gcnew SolidBrush(Color::Blue);
			Pen^ pen = gcnew Pen(Color::Black, 1);
			graphics->FillEllipse(brush, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
			graphics->DrawEllipse(pen, (float)(m_x - m_radius), (float)(m_y - m_radius), (float)(2 * m_radius), (float)(2 * m_radius));
		}
	}
};