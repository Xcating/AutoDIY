#include <iostream>
#include <fstream>
#include <string>
#include<map>

using namespace std;

string name, Fname, author, introduction, inputKey, bg, difficulty;
string point1 = "否", point2 = "否", point3 = "否", point4 = "否";
string p1 = "0", p2 = "0", p3 = "0", p4 = "0", p5 = "0";
int wave;
string sun;

void File() {
    cout << "请输入关卡的文件名：" << endl;
    cin >> name;
    cout << "请输入关卡的名称：" << endl;
    cin >> Fname;
    cout << "请输入关卡的作者：" << endl;
    cin >> author;
    int i = 1;
    cout << "===开始编辑关卡简介=== (输入end进入下一项)" << endl;
    while (true) {
        cout << "现在输入第" << i << "行关卡简介：" << endl;
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
        file << "[文件信息]\n";
        file << "关卡名=" + Fname + "\n";
        file << "作者名=" + author + "\n";
        file << "关卡简介=" + introduction + "\n";
        file.close();
    }
    else {
        cout << "文件加载失败" << endl;
    }
}
void Other() {
    cout << "请输入关卡背景，可以是：\n潜意识场景(1)，逻辑场景(2)，枫威入口(3)，枫威瀑布(4)，枫威湖(5)，枫威水帘洞(6)，迷蒙之沼(7)，迷蒙神隐(8)，凌绽原野(9)" << endl;
    map<int, string> bgOptions{
        {1, "潜意识场景"},
        {2, "逻辑场景"},
        {3, "枫威入口"},
        {4, "枫威瀑布"},
        {5, "枫威湖"},
        {6, "枫威水帘洞"},
        {7, "迷蒙之沼"},
        {8, "迷蒙神隐"},
        {9, "凌绽原野"}
    };
    int bgKey;
    cin >> bgKey;
    cout << "你选择了：" << bgOptions[bgKey] << endl;
    string bg = bgOptions[bgKey];

    cout << "=============" << endl;
    cout << "请输入关卡难度，可以是：\nEasy(1)，Medium(2)，Hard(3)，Impossible(4)，Unbalanced(5)\n" << endl;
    map<int, string> difficultyOptions{
        {1, "Easy"},
        {2, "Medium"},
        {3, "Hard"},
        {4, "Impossible"},
        {5, "Unbalanced"}
    };
    int difficultyKey;
    cin >> difficultyKey;
    cout << "你选择了：" << difficultyOptions[difficultyKey] << endl;
    string difficulty = difficultyOptions[difficultyKey];

    cout << "请输入英杰之锁情况：" << endl;
    bool point1, point2, point3, point4;
    cout << "卡槽虚无(最多4卡)： (1是/0否)" << endl;
    cin >> point1;
    cout << "推车虚无(无推车)： (1是/0否)" << endl;
    cin >> point2;
    cout << "阳光虚无(最多500阳光)： (1是/0否)" << endl;
    cin >> point3;
    cout << "加点虚无(禁用任何加点)： (1是/0否)" << endl;
    cin >> point4;

    if (!point4) {
        cout << "请输入加点情况：" << endl;
        cout << "卡槽加点" << endl;
        cin >> p1;
        cout << "阳光加点" << endl;
        cin >> p2;
        cout << "推车加点" << endl;
        cin >> p3;
        cout << "被动加点" << endl;
        cin >> p4;
        cout << "主动加点" << endl;
        cin >> p5;
    }

    int sun;
    cout << "请输入初始阳光：" << endl;
    cin >> sun;

    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[基础信息]\n";
        file << "关卡背景=" + bg + "\n";
        file << "关卡难度=" + difficulty + "\n";
        file << "所选路线=导向蓟线\n";
        file << "卡槽虚无=" + to_string(point1) + "\n";
        file << "推车虚无=" + to_string(point2) + "\n";
        file << "阳光虚无=" + to_string(point3) + "\n";
        file << "加点虚无=" + to_string(point4) + "\n";
        file << "卡槽加点=" + p1 + "\n";
        file << "阳光加点=" + p2 + "\n";
        file << "推车加点=" + p3 + "\n";
        file << "被动加点=" + p4 + "\n";
        file << "主动加点=" + p5 + "\n";
        file << "开始阳光=" + to_string(sun) + "\n";
        file.close();
    }
    else {
        cout << "文件加载失败" << endl;
    }
}
void Attack() {
    // 创建僵尸ID和僵尸类型的映射关系
    map<int, string> zombieMap = {
        {1, "普通僵尸"},
        {2, "旗帜僵尸"},
        {3, "路障僵尸"},
        {4, "铁桶僵尸"},
        {5, "撑杆僵尸"},
        {6, "萤火虫僵尸"},
        {7, "弓箭僵尸"},
        {8, "女巫僵尸"},
        {9, "永动轮僵尸"}
    };

    int wave;
    cout << "请输入总波数：" << endl;
    cin >> wave;

    ofstream file(name + ".txt", ios::app);
    if (file.is_open()) {
        file << "[波数信息]\n";
        file << "关卡总波数=" + to_string(wave) + "\n";
        file.close();
    }

    for (int i = 1; i <= wave; i++) {
        cout << "当前为第" << i << "波==========\n这波需要出几个僵尸？" << endl;
        int n;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            cout << "当前为第" << i << "波第" << j << "个僵尸==========是什么僵尸？ [普僵(1),旗帜(2),路障(3),铁桶(4),撑杆(5),萤火虫(6),弓箭(7),女巫(8),永动轮(9)]" << endl;
            int ZombieID;
            cin >> ZombieID;

            string Zombie = zombieMap[ZombieID];
            cout << "你选择了：" << Zombie << endl;

            cout << endl;
            cout << "请问这个僵尸在哪一行？ (1~5为正常行数，-1 或 6为随机，-2 或 7为系统优选)" << endl;
            int h;
            cin >> h;

            if (h >= 1 && h <= 5) {
                h--;
            }

            ofstream file(name + ".txt", ios::app);
            if (file.is_open()) {
                file << "第" + to_string(i) + "波僵尸" + to_string(j) + "类型=" + Zombie + "\n";
                file << "第" + to_string(i) + "波僵尸" + to_string(j) + "行数=" + to_string(h) + "\n";
                file.close();
            }
        }
    }
}
void Card() {
    cout << "卡槽数量是多少？" << endl;
    int number;
    cin >> number;
    cout << "启用自选卡吗？ (1启用 / 0不启用)" << endl;
    int cardCase;
    string card;
    cin >> cardCase;
    card = cardCase ? "是" : "否";
    string Acard = "", Scard = "", Ecard = "";
    if (cardCase == 0) {
        cout << "你没有启用自选卡，需要什么卡槽？ (输入格式：豌豆射手, 向日葵, 光菱角) [注意逗号是半角/英文的]";
        cin >> Acard;
    }
    else {
        cout << "你要禁用什么植物？ 输入0忽略此项 (输入格式：豌豆射手, 向日葵, 光菱角) [注意逗号是半角/英文的]" << endl;
        cin >> Scard;
        cout << "你要强制携带什么植物？ 输入0忽略此项 (输入格式：豌豆射手, 向日葵, 光菱角) [注意逗号是半角/英文的]" << endl;
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
        file << "[卡片信息]\n";
        file << "卡槽数量=" + to_string(number) + "\n";
        file << "不启用选卡=" + card + "\n";
        file << "不预览僵尸=否\n";
        file << "卡槽卡片=" + Acard + "\n";
        file << "禁用卡片=\n";
        file << "强制携带卡片=" + Ecard + "\n";
        file << "未拥有卡片=" + Scard + "\n";
        file.close();
    }
    else {
        cout << "文件加载失败" << endl;
    }
}
int main()
{
	File();
	Other();
    Attack();
    Card();
    printf("\n关卡文档已经生成，使用恶魂的GDFMaker生成GDF文件即可使用！欢迎下次使用！\n    Powered by Xcating");
    //Powered by Xcating
    cin.get();
    return 0;
}