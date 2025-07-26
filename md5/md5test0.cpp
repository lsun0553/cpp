/**  ��������� ��������� ���� ��� ��������� ����� � ������ � �������� ����������.
��� ������� ����� �����������  MD5-��� � ������� ������ MD5::fileToHash � ������� ��������� �� �������.
���� ���� � ������ �� �������, ��������� ���������  ��� ��������� ���������.
 */
#include <iostream>
#include "md5.hpp"
using std::cout, std::endl;

int main(int argc, char** argv) {
    if(argc > 1) {
    // ��������� md5-��� ��� ������� �� ������, ��������� � ����������.
        for(int i = 1; i < argc; ++i) {
            cout << MD5::fileToHash(argv[i]) << endl;}
    } else { // ���� ���������� ��� - ������� ���������.
        cout << "Usage:" << endl
        << "\t" << argv[0] << " <file-to-hash>" << endl;
    }
    return 0;
}
