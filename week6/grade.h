#pragma once
#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

// �����ε� �Լ�
double grade(double, double, double);
double grade(double, double, std::vector<double>&);
double grade(const Student_info&);

bool fgrade(const Student_info&);
bool pgrade(const Student_info&); // �ʿ� ���� ������ ...

#endif // !GUARD_grade_h
