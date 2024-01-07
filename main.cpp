#include <iostream>
#include <fstream>
#include <string>
#include<map>

using namespace std;

string name, Fname, author, introduction, inputKey, bg, difficulty;
string point1 = "��", point2 = "��", point3 = "��", point4 = "��";
string p1 = "0", p2 = "0", p3 = "0", p4 = "0", p5 = "0";
int wave;
string sun;

void File() {
    cout << "������ؿ����ļ�����" << endl;
    cin >> name;
    cout << "������ؿ������ƣ�" << endl;
    cin >> Fname;
    cout << "������ؿ������ߣ�" << endl;
    cin >> author;
    int i = 1;
    cout << "===��ʼ�༭�ؿ����=== (����end������һ��)" << endl;
    while (true) {
        cout << "���������" << i << "�йؿ���飺" << endl;
        i++;
        string x;
        cin >> x;
        if (x == "end") {
            break;
        }
        introduction += x;
        introduction += "<br/>";
    }
    introduction = introduction.substr(0, introduction.size() - 5);
    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[�ļ���Ϣ]\n";
        file << "�ؿ���=" + Fname + "\n";
        file << "������=" + author + "\n";
        file << "�ؿ����=" + introduction + "\n";
        file.close();
    }
    else {
        cout << "�ļ�����ʧ��" << endl;
    }
}
void Other() {
    cout << "������ؿ������������ǣ�\nǱ��ʶ����(1)���߼�����(2)���������(3)�������ٲ�(4)��������(5)������ˮ����(6)������֮��(7)����������(8)������ԭҰ(9)" << endl;
    map<int, string> bgOptions{
        {1, "Ǳ��ʶ����"},
        {2, "�߼�����"},
        {3, "�������"},
        {4, "�����ٲ�"},
        {5, "������"},
        {6, "����ˮ����"},
        {7, "����֮��"},
        {8, "��������"},
        {9, "����ԭҰ"}
    };
    int bgKey;
    cin >> bgKey;
    cout << "��ѡ���ˣ�" << bgOptions[bgKey] << endl;
    string bg = bgOptions[bgKey];

    cout << "=============" << endl;
    cout << "������ؿ��Ѷȣ������ǣ�\nEasy(1)��Medium(2)��Hard(3)��Impossible(4)��Unbalanced(5)\n" << endl;
    map<int, string> difficultyOptions{
        {1, "Easy"},
        {2, "Medium"},
        {3, "Hard"},
        {4, "Impossible"},
        {5, "Unbalanced"}
    };
    int difficultyKey;
    cin >> difficultyKey;
    cout << "��ѡ���ˣ�" << difficultyOptions[difficultyKey] << endl;
    string difficulty = difficultyOptions[difficultyKey];

    cout << "������Ӣ��֮�������" << endl;
    bool point1, point2, point3, point4;
    cout << "��������(���4��)�� (1��/0��)" << endl;
    cin >> point1;
    cout << "�Ƴ�����(���Ƴ�)�� (1��/0��)" << endl;
    cin >> point2;
    cout << "��������(���500����)�� (1��/0��)" << endl;
    cin >> point3;
    cout << "�ӵ�����(�����κμӵ�)�� (1��/0��)" << endl;
    cin >> point4;

    if (!point4) {
        cout << "������ӵ������" << endl;
        cout << "���ۼӵ�" << endl;
        cin >> p1;
        cout << "����ӵ�" << endl;
        cin >> p2;
        cout << "�Ƴ��ӵ�" << endl;
        cin >> p3;
        cout << "�����ӵ�" << endl;
        cin >> p4;
        cout << "�����ӵ�" << endl;
        cin >> p5;
    }

    int sun;
    cout << "�������ʼ���⣺" << endl;
    cin >> sun;

    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[������Ϣ]\n";
        file << "�ؿ�����=" + bg + "\n";
        file << "�ؿ��Ѷ�=" + difficulty + "\n";
        file << "��ѡ·��=������\n";
        file << "��������=" + to_string(point1) + "\n";
        file << "�Ƴ�����=" + to_string(point2) + "\n";
        file << "��������=" + to_string(point3) + "\n";
        file << "�ӵ�����=" + to_string(point4) + "\n";
        file << "���ۼӵ�=" + p1 + "\n";
        file << "����ӵ�=" + p2 + "\n";
        file << "�Ƴ��ӵ�=" + p3 + "\n";
        file << "�����ӵ�=" + p4 + "\n";
        file << "�����ӵ�=" + p5 + "\n";
        file << "��ʼ����=" + to_string(sun) + "\n";
        file.close();
    }
    else {
        cout << "�ļ�����ʧ��" << endl;
    }
}
void Attack() {
    // ������ʬID�ͽ�ʬ���͵�ӳ���ϵ
    map<int, string> zombieMap = {
        {1, "��ͨ��ʬ"},
        {2, "���Ľ�ʬ"},
        {3, "·�Ͻ�ʬ"},
        {4, "��Ͱ��ʬ"},
        {5, "�Ÿ˽�ʬ"},
        {6, "ө��潩ʬ"},
        {7, "������ʬ"},
        {8, "Ů�׽�ʬ"},
        {9, "�����ֽ�ʬ"}
    };

    int wave;
    cout << "�������ܲ�����" << endl;
    cin >> wave;

    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[������Ϣ]\n";
        file << "�ؿ��ܲ���=" + to_string(wave) + "\n";
        file.close();
    }

    for (int i = 1; i <= wave; i++) {
        cout << "��ǰΪ��" << i << "��==========\n�Ⲩ��Ҫ��������ʬ��" << endl;
        int n;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            cout << "��ǰΪ��" << i << "����" << j << "����ʬ==========��ʲô��ʬ�� [�ս�(1),����(2),·��(3),��Ͱ(4),�Ÿ�(5),ө���(6),����(7),Ů��(8),������(9)]" << endl;
            int ZombieID;
            cin >> ZombieID;

            string Zombie = zombieMap[ZombieID];
            cout << "��ѡ���ˣ�" << Zombie << endl;

            cout << endl;
            cout << "���������ʬ����һ�У� (1~5Ϊ����������-1 �� 6Ϊ�����-2 �� 7Ϊϵͳ��ѡ)" << endl;
            int h;
            cin >> h;

            if (h >= 1 && h <= 5) {
                h--;
            }

            ofstream file(name + ".txt", ios::app);
            if (file.is_open()) {
                file << "��" + to_string(i) + "����ʬ" + to_string(j) + "����=" + Zombie + "\n";
                file << "��" + to_string(i) + "����ʬ" + to_string(j) + "����=" + to_string(h) + "\n";
                file.close();
            }
        }
    }
}
void Card() {
    cout << "���������Ƕ��٣�" << endl;
    int number;
    cin >> number;
    cout << "������ѡ���� (1���� / 0������)" << endl;
    int cardCase;
    string card;
    cin >> cardCase;
    card = cardCase ? "��" : "��";
    string Acard = "", Scard = "", Ecard = "";
    if (cardCase == 0) {
        cout << "��û��������ѡ������Ҫʲô���ۣ� (�����ʽ���㶹����, ���տ�, �����) [ע�ⶺ���ǰ��/Ӣ�ĵ�]";
        cin >> Acard;
    }
    else {
        cout << "��Ҫ����ʲôֲ� ����0���Դ��� (�����ʽ���㶹����, ���տ�, �����) [ע�ⶺ���ǰ��/Ӣ�ĵ�]" << endl;
        cin >> Scard;
        cout << "��Ҫǿ��Я��ʲôֲ� ����0���Դ��� (�����ʽ���㶹����, ���տ�, �����) [ע�ⶺ���ǰ��/Ӣ�ĵ�]" << endl;
        cin >> Ecard;
        if (Scard == "0") {
            Scard = "";
        }
        if (Ecard == "0") {
            Ecard = "";
        }
    }
    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[��Ƭ��Ϣ]\n";
        file << "��������=" + to_string(number) + "\n";
        file << "������ѡ��=" + card + "\n";
        file << "��Ԥ����ʬ=��\n";
        file << "���ۿ�Ƭ=" + Acard + "\n";
        file << "���ÿ�Ƭ=\n";
        file << "ǿ��Я����Ƭ=" + Ecard + "\n";
        file << "δӵ�п�Ƭ=" + Scard + "\n";
        file.close();
    }
    else {
        cout << "�ļ�����ʧ��" << endl;
    }
}
int main()
{
	File();
	Other();
    Attack();
    Card();
    printf("\n�ؿ��ĵ��Ѿ����ɣ�ʹ�ö���GDFMaker����GDF�ļ�����ʹ�ã���ӭ�´�ʹ�ã�\n    Powered by Xcating");
    //Powered by Xcating
    cin.get();
    return 0;
}