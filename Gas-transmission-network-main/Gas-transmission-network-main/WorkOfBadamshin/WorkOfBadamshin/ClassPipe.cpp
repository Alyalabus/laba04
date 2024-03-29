#include "ClassPipe.h"
#include "Verification.h"
#include <iomanip>


// ������������� �����
Pipe::Pipe() : used(false)
{
	maxIdPipe++;
	this->id = maxIdPipe;
	this->length = verification::GetNumericValue<double>("������� ����� �����, ����������� - ���������, �������� �� 10 �� 100 �� (������������� ����� �����, ����� �������� ������� ����� ����������� \".\"): ",
		"������!!! �� ����� ���-�� ����������.\n����� ����� ����� ���� ���� ����� ������, ���� ������ � ��������� ������, ������� � ��������� �� 10 �� 100 ��, ��������� ����!!!", 10.0, 100.0);

	this->diameter = verification::GetNumericValue<double>("������� ������� �����, ����������� ����������, �������� �� 500 �� 1420 �� (������������� ����� �����, ����� �������� ������� ����� ����������� \".\"): ",
		"������!!! �� ����� ���-�� ����������.\n������� ����� ����� ���� ���� ����� ������, ���� ������ � ��������� ������, ������� � ��������� �� 500 �� 1420 ��, ��������� ����!!!", 500.0, 1420.0);

	this->repair = verification::GetBoolValue("������� ��������� �� ����� � �������, ���� ��, �� ������� \"y\" �� ����������, ���� �� ���, �������� �� \"n\": ",
		"\n����������� �������! ��������� ���� �� ��������� ���� ��������, �������� �� \"y\", ���� ��, �� \"n\", ���� ���!!!");
}

// ���������� �� �����
Pipe::Pipe(std::ifstream& fin) : used(false)
{
	fin >> this->id >> this->length >> this->diameter >> this->repair >> this->outId >> this->inId >> this->used;
}

// �������������� �����
void Pipe::GhangePipe()
{
	this->repair = verification::GetBoolValue("������� ����� ��������� ��� �����, ���� ��� � �������, �� ������� \"y\" �� ����������, ���� �� ���, �������� �� \"n\": ",
		"\n����������� �������! ��������� ���� �� ��������� ���� ��������, �������� �� \"y\", ���� ��, �� \"n\", ���� ���: ");
}

// ���������� ����� � ����
void Pipe::SaveToFile(std::ofstream& fout)
{
	fout << id << std::endl
		<< length << std::endl
		<< diameter << std::endl
		<< repair << std::endl
		<< outId << std::endl
		<< inId << std::endl
		<< used << std::endl;
}

// ���������� InId � OutId
void Pipe::SetInId(size_t id)
{
	inId = id;
}

void Pipe::SetOutId(size_t id)
{
	outId = id;
}

// �������� InId � OutId
size_t Pipe::GetInId() const
{
	return inId;
}

size_t Pipe::GetOutId() const
{
	return outId;
}

// ���������� �������� ���� used
void Pipe::SetUsed(bool flag)
{
	used = flag;
}

// ������ �������� ���� used
bool Pipe::IsUsed() const
{
	return used;
}

// �������� ������������ id
size_t Pipe::GetMaxID()
{
	return maxIdPipe;
}

bool Pipe::GetRepairStatus() const
{
	return repair;
}

double Pipe::GetLength() const
{
	return length;
}

double Pipe::GetProductivity() const
{
	return sqrt(diameter*diameter*diameter*diameter*diameter / length);
}