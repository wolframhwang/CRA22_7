#pragma once

#include "common.h"

class Condition {
public:
	virtual bool isEqual(const Employee &employee) const = 0;
};

class ConditionEmployeeNum : public Condition {
public:
	ConditionEmployeeNum(const unsigned long &employeeNum) :
		employeeNum_(employeeNum) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	unsigned long employeeNum_;
};

class ConditionNameFirst : public Condition {
public:
	ConditionNameFirst(const string &first) :
		first_(first) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	string first_;
};

class ConditionNameLast : public Condition {
public:
	ConditionNameLast(const string &last) :
		last_(last) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	string last_;
};

class ConditionName : public Condition {
public:
	ConditionName(string first, string last) :
		nameFirst(first), nameLast(last) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	ConditionNameFirst nameFirst;
	ConditionNameLast nameLast;
};

class ConditionCl : public Condition {
public:
	ConditionCl(const CL &cl) :
		cl_(cl) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	CL cl_;
};

class ConditionPhoneNumMid : public Condition {
public:
	ConditionPhoneNumMid(int mid) :
		mid_(mid) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	int mid_;
};

class ConditionPhoneNumEnd : public Condition {
public:
	ConditionPhoneNumEnd(int end) :
		end_(end) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	int end_;
};

class ConditionPhoneNum : public Condition {
public:
	ConditionPhoneNum(int mid, int end) :
		phoneNumMid_(mid), phoneNumEnd_(end) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	ConditionPhoneNumMid phoneNumMid_;
	ConditionPhoneNumEnd phoneNumEnd_;
};

class ConditionBirthdayYear : public Condition {
public:
	ConditionBirthdayYear(const int &year) :
		year_(year) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	int year_;
};

class ConditionBirthdayMonth : public Condition {
public:
	ConditionBirthdayMonth(const int &month) :
		month_(month) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	int month_;
};

class ConditionBirthdayDay : public Condition {
public:
	ConditionBirthdayDay(const int &day) :
		day_(day) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	int day_;
};

class ConditionBirthday : public Condition {
public:
	ConditionBirthday(const int &year, const int &month, const int &day) :
		conditionBirthdayYear(year), conditionBirthdayMonth(month), conditionBirthdayDay(day) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	ConditionBirthdayYear  conditionBirthdayYear;
	ConditionBirthdayMonth conditionBirthdayMonth;
	ConditionBirthdayDay   conditionBirthdayDay;
};

class ConditionCerti : public Condition {
public:
	ConditionCerti(const Grade &certi) :
		certi_(certi) {
	}

	virtual bool isEqual(const Employee &employee) const override {
		return true;
	}

private:
	Grade certi_;
};
