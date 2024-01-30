#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

#ifdef __WIN32__
#include <windows.h>
#define cls() system("cls")
#define Pause() system("pause")
#else
#include <unistd.h>
#define Sleep(x) usleep(x * 1000)
#define cls() system("clear")
#define Pause() system("echo 请按任意键继续. . .; read")
#endif

#define int long long
#define debug() cout << "come here" << endl
#define EASY_FIGHTING_ENGINE 1

#ifndef FIGHTING_ENGINE
#define FIGHTING_ENGINE EASY_FIGHTING_ENGINE
// 这意味着以后还会有HARD_FIGTING_ENGINE
#endif

using namespace std;
mt19937_64 mrand(time(0));
int now = 1, resettime = 0, dot = 0;
int craft = 1, bag = 5, reload = 0, spining = 0, summoner = 0, now_craft = 3,
    now_bag = 3, now_reload = 2, now_spining = 2, now_summoner = 1;
bool bubble = 0, ygg = 0, teye = 0;
int now_color = 0, cifen = 0;
const int now_petals_number = 65;
int now_place = 1;
int go[6][6] = {0, 0, 0, 0, 0, 0,  0, 0,  5, 3, 10, 5, 0, 5, 0, 7,  8, 7,
                0, 3, 7, 0, 5, 10, 0, 10, 8, 5, 0,  3, 0, 5, 7, 10, 3, 0};
vector<string> petals = {
    "",          "wing",          "faster",  "light",    "sand",
    "claw",      "blood stinger", "stinger", "cutter",   "uranium",
    "yin yang",  "rice",          "leaf",    "corn",     "clover",
    "yucca",     "salt",          "bone",    "ant egg",  "beetle egg",
    "relic",     "tomato",        "rose",    "honey",    "orange",
    "missile",   "antennae",      "pollen",  "pea",      "rock",
    "heavy",     "basic",         "lris",    "grapes",   "cactus",
    "bubble",    "dandelion",     "web",     "pincer",   "magnet",
    "ygg",       "starfish",      "pearl",   "lighting", "jelly",
    "shell",     "dahlia",        "sponge",  "soil",     "fangs",
    "third eye", "stick",         "powder",  "air",      "basil",
    "poo",       "lotus",         "blub",    "cotton",   "carrot",
    "plank",     "root",          "bur",     "rubber",   "mark",
    "ankh"};
vector<string> garden = {"rock",       "ladybug",     "bee",       "baby ant",
                         "worker ant", "soldier ant", "queen ant", "hornet",
                         "centipede",  "spider",      "digger",    "dandelion",
                         "bumble bee", "fly",         "moth",      "roach"};
vector<string> ocean = {"bubble",    "shell",  "starfish", "crab",
                        "jellyfish", "sponge", "leech"};
vector<string> desert = {"cactus",        "beetle",   "desert centipede",
                         "shiny ladybug", "scorpion", "soldier fire ant",
                         "sandstorm"};
vector<string> jungle = {"leafbug",        "wasp",
                         "mantis",         "bush",
                         "baby termite",   "solider termite",
                         "worker termite", "termite overmind",
                         "evil centipede", "dark ladybug"};
vector<string> ant_hole = {
    "baby ant",      "worker ant",      "solider ant",
    "baby fire ant", "worker fire ant", "solider fire ant",
    "baby termite",  "worker termite",  "solider termite"};
vector<string> ant_hole_ultra_super = {"ant queen", "fire ant queen",
                                       "termite overmind"};
vector<string> hel = {"hel beetle"};
vector<int> level_need_exp = {0, 5, 20, 80, 200};
map<string, int> id;
int num[1001][10], expp;
vector<string> level = {" ",         "common", "unusual", "rare", "epic",
                        "legendary", "mythic", "ultra",   "super"};
vector<int> level_exp = {0,     1,      5,         50,          500,
                         10000, 500000, 500000000, 500000000000};
vector<int> level_craft_make = {0, 0, 40, 30, 20, 10, 3, 2, 1};
pair<int, string> ussing[20];

#ifdef __WIN32__
void bling() {
  for (int i = 0; i <= 3; i++) {
    system("color 1A");
    Sleep(10);
    system("color 2B");
    Sleep(10);
    system("color 3C");
    Sleep(10);
    system("color 4D");
    Sleep(10);
    system("color 5D");
    Sleep(10);
    system("color 6E");
    Sleep(10);
    system("color 7F");
    Sleep(10);
  }
  switch (now_color) {
  case 2:
    system("color 20");
    break;
  case 8:
    system("color 80");
    break;
  case 9:
    system("color 90");
    break;
  case 10:
    system("color A0");
    break;
  case 14:
    system("color E0");
    break;
  default:
    system("color 07");
  }
  cls();
  return;
}
#else
void bling() {
  // TODO
  return;
}
#endif

void refresh_map() {
  switch (now_place) {
  case 1:
    system("color A0");
    now_color = 10;
    break;
  case 2:
    system("color E0");
    now_color = 14;
    break;
  case 3:
    system("color 90");
    now_color = 9;
    break;
  case 4:
    system("color 20");
    now_color = 2;
    break;
  case 5:
    system("color 80");
    now_color = 8;
  }
}

void going() {
  cout << "请问要去哪里：[1]花园 [2]沙漠 [3]海洋 [4]丛林 [5]蚁穴\n";
  int where;
  cin >> where;
  if (where < 1 || where > 5) {
    cout << "该地点不存在";
    return;
  }
  cout << "正在前往中...\n";
  int go_time = go[now_place][where] * 1000;
  if (now_place != where && bubble && mrand() % 100 == 1) {
    cout << "你在赶路的时候失误撞到ultra死了......\n";
    return;
  } else if (now_place != where && bubble) {
    go_time /= 2;
  }
  Sleep(go_time);
  now_place = where;
  return;
}

void finding() {
  string s;
  cout << "你要查询哪种花瓣？（输入花瓣英文，小写）";
  cin >> s;
  if (id.find(s) == id.end()) {
    cout << "现版本还未有该花瓣或不存在\n";
    return;
  }
  for (int i = 1; i <= 8; i++) {
    cout << "你有" << level[i] << "的" << s << "花瓣" << num[id[s]][i]
         << "张\n";
  }
  return;
}

void skilling() {
  cout << "你要点哪个技能（[1]合成 [2]物品栏 [3]花瓣恢复速度 [4]花瓣旋转速度 "
          "[5]增加召唤物血量）：";
  int op;
  cin >> op;
  switch (op) {
  case 1:
    if (craft == 7) {
      cout << "已满级\n";
      break;
    }
    if (dot >= now_craft) {
      dot -= now_craft;
      now_craft += 2;
      craft++;
      cout << "升级成功！\n";
      cout << "剩余" << dot << "个技能点\n";
      break;
    }
    cout << "技能点不足！\n";
    cout << "你只有" << dot << "个技能点，需要" << now_craft << "个技能点\n";
    break;
  case 2:
    if (bag == 10) {
      cout << "已满级\n";
      break;
    }
    if (dot >= now_bag) {
      dot -= now_bag;
      now_bag += 3;
      bag++;
      cout << "升级成功！\n";
      cout << "剩余" << dot << "个技能点\n";
      break;
    }
    cout << "技能点不足！\n";
    cout << "你只有" << dot << "个技能点，需要" << now_bag << "个技能点\n";
    break;
  case 3:
    if (reload == 8) {
      cout << "已满级\n";
    }
    if (dot >= now_reload) {
      dot -= now_reload;
      now_reload += 1;
      reload++;
      cout << "升级成功！\n";
      cout << "剩余" << dot << "个技能点\n";
      break;
    }
    cout << "技能点不足！\n";
    cout << "你只有" << dot << "个技能点，需要" << now_reload << "个技能点\n";
    break;
  case 4:
    if (spining == 6) {
      cout << "已满级\n";
      break;
    }
    if (dot >= now_spining) {
      dot -= now_spining;
      now_spining += 1;
      spining++;
      cout << "升级成功！\n";
      cout << "剩余" << dot << "个技能点\n";
      break;
    }
    cout << "技能点不足！\n";
    cout << "你只有" << dot << "个技能点，需要" << now_spining << "个技能点\n";
    break;
  case 5:
    if (summoner == 6) {
      cout << "已满级\n";
      break;
    }
    if (dot >= now_summoner) {
      dot -= now_summoner;
      now_summoner += 1;
      summoner++;
      cout << "升级成功！\n";
      cout << "剩余" << dot << "个技能点\n";
      break;
    }
    cout << "技能点不足！\n";
    cout << "你只有" << dot << "个技能点,需要" << now_summoner << "个技能点\n";
  }
  return;
}

void crafting() {
  cout << "请问要合成什么（输入英文，小写）：";
  string thing_to_craft;
  cin >> thing_to_craft;
  cout << "请输入要合成的等级（[1]common->unusual [2]unusual->rare "
          "[3]rare->epic "
          "[4]epic->legendary [5]legendary->mythic [6]mythic->ultra "
          "[7]ultra->super）：";
  int craft_level;
  cin >> craft_level;
  if (craft_level > craft) {
    cout << "你还未解锁该等级的合成\n";
    return;
  } else if (craft_level > 7 || craft_level < 1) {
    cout << "没有该等级的合成！！！\n";
    return;
  }
  if (id.find(thing_to_craft) == id.end()) {
    cout << "现版本还未有该花瓣或不存在\n";
    return;
  }
  if (num[id[thing_to_craft]][craft_level] < 5) {
    cout << "花瓣不足，合成失败\n";
  }
  cout << "你现在有" << num[id[thing_to_craft]][craft_level] << "个"
       << craft_level << "级的" << thing_to_craft
       << "花瓣，要合成几个（最少五个）？";
  int number;
  cin >> number;
  if (number < 5) {
    cout << "不能合成少于五个\n";
    return;
  }
  num[id[thing_to_craft]][craft_level] -= number;
  int less = number, got = 0;
  while (less >= 5) {
    if (mrand() % 100 < level_craft_make[craft_level + 1]) {
      got++;
      less -= 5;
    } else {
      less -= mrand() % 4 + 1;
    }
  }
  num[id[thing_to_craft]][craft_level] += less;
  num[id[thing_to_craft]][craft_level + 1] += got;
  if (craft_level + 1 == 8 && got > 0) {
    cout << "你合出了" << got << "个Super " << thing_to_craft << "!!!";
    Sleep(1000);
    cls();
    cout << "恭喜！！！";
    Sleep(300);
    bling();
    cls();
  } else
    cout << "合成后剩余" << less << "个，合成出了" << got << "个\n";
  if (got < number / 300 && !(craft_level + 1 == 8 && got >= 1))
    cout << "惨\n";
}

void absorbing() {
  if (now == 170) {
    cout << "已满级\n";
    return;
  }
  cout << "请问要烧哪个卡（输入英文，小写）：";
  string petals;
  cin >> petals;
  map<string, int>::iterator iter;
  iter = id.find(petals);
  if (iter == id.end()) {
    cout << "现版本还未有该花瓣或不存在\n";
    return;
  }
  cout << "请问要烧的花瓣等级是（[1]common [2]unusual [3]rare [4]epic "
          "[5]legendary [6]mythic [7]ultra [8]super）：";
  int absorb_level;
  cin >> absorb_level;
  if (absorb_level < 1 || absorb_level > 8) {
    cout << "错误等级\n";
    return;
  }
  if (num[id[petals]][absorb_level] == 0) {
    cout << "你没有该等级的花瓣\n";
    return;
  }
  cout << "请问要烧几个？你有" << num[id[petals]][absorb_level]
       << "个该等级的这种花瓣";
  int absorb_number;
  cin >> absorb_number;
  if (num[id[petals]][absorb_level] < absorb_number || absorb_number < 0) {
    cout << "错误，不可烧小于0个或大于你拥有的数量的花瓣";
    return;
  }
  if (absorb_level > 6) {
    cout << "该等级的卡片较稀有，确定销毁吗？[y]是 [n]否";
    int a;
    cin >> a;
    if (a == 'n')
      return;
  }
  num[id[petals]][absorb_level] -= absorb_number;
  expp += absorb_number * level_exp[absorb_level];
  int times = 0;
  while (expp >= level_need_exp[now] && now < 170) {
    expp -= level_need_exp[now];
    now++;
    dot++;
    times++;
  }
  if (absorb_level == 8) {
    vector<string> absorb_super = {"",    "你烧了一个", "S",     "Su",
                                   "Sup", "Supe",       "Super", "!!!"};
    for (int i = 1; i <= 6; i++) {
      cout << absorb_super[i];
      Sleep(((i - 1) % 5 == 0 ? 1000 : 500) * 1000);
      cls();
    }
  }
  cout << "升了" << times << "级\n";
  cout << "还差" << level_need_exp[now] - expp << "点经验升到下一级\n";
  if (petals == "magnet" && absorb_level == 7) {
    cout << "薛皓文永远的痛\n";
    cout << "恭喜你获得 磁粉 ×" << absorb_number << "\n";
    for (int i = 1; i <= absorb_number; i++) {
      cifen += 1;
      cifen += mrand() % 3;
    }
  }
  return;
}

void dictionary() {
  cout << "请问你想了解什么（[1]关于各个地图 [2]关于合成 [3]关于升级 "
          "[4]关于花瓣 "
          "[5]关于作者）：";
  int op;
  cin >> op;
  if (op == 1) {
    cout << "花园生物速度比你慢一点，沙漠里的生物都比你速度快\n";
    cout << "海洋里的生物都可以追上你，雨林还是半成品\n";
    cout << "至于蚁穴...不会真的有人会在蚁穴死吧！！！\n";
  } else if (op == 2) {
    cout << "common->unusual 40%\n";
    cout << "unusual->rare 30%\n";
    cout << "rare->epic 20%\n";
    cout << "epic->legendary 10%\n";
    cout << "legendary->mythic 3%\n";
    cout << "mythic->ultra 2%\n";
    cout << "ultra->super 1%\n";
    cout << "本游戏使用c++内置随机数，不存在玄学\n";
  } else if (op == 3) {
    cout << "common=1exp,unusual=5exp,rare=50exp,epic=500exp,\n";
    cout << "legendary=10kexp,mythic=500kexp,ultra=50millionexp,super="
            "50billionexp\n";
    cout << "满级为170级,0-1/1-2/2-3/3-4分别为5/20/80/"
            "200exp,后面每级为上一级的1.085倍（向下取整）\n";
  } else if (op == 4) {
    cout << "现版本有的花瓣有：\n";
    for (int i = 1; i <= now_petals_number; i++)
      cout << petals[i] << ", "[i == now_petals_number] << " \n"[i % 10 == 0];
    cout << "\n";
  } else if (op == 5) {
    cout << "作者，MCYYDS\n";
    cout << "第一张U：476l wing=11m wing=1U wing\n";
    cout << "第二张U：15m wing=1U wing\n";
    cout << "第三张U：U egg，蚁后掉的\n";
    cout << "第四张U：18根m骨头没了后出了U relic...（已烧掉）\n";
    cout << "第五张U：100张青没出之后蚁后掉了个U egg\n";
    cout << "第六张U：蚁后叒掉了个U egg\n";
  } else {
    cout << "没有该选项\n";
  }
}

void equiping() {
  cout << "你现在的装备是：\n||-";
  for (int i = 1; i <= bag; i++) {
    if (!ussing[i].first) {
      cout << "空";
    } else {
      cout << level[ussing[i].first] << " " << petals[id[ussing[i].second]];
    }
    if (i < bag)
      cout << "-||-";
    else
      cout << "-||\n";
  }
  cout << "请问要更换或卸下第几个花瓣（从左数）：";
  int num_petals;
  cin >> num_petals;
  if (num_petals < 1 || num_petals > bag) {
    cout << "没有该槽位\n";
    return;
  }
  cout << "请问要更换成什么花瓣（输入花瓣英文小写名称，或按[0]卸下）：";
  string equip_petals;
  cin >> equip_petals;
  if (equip_petals == "0") {
    num[id[ussing[num_petals].second]][ussing[num_petals].first]++;
    ussing[num_petals].second = "";
    ussing[num_petals].first = 0;
    cout << "卸下成功！\n";
    return;
  }
  cout << "请问要更换成什么等级的 " << equip_petals
       << "（[1]common [2]unusual "
          "[3]rare [4]epic [5]legendary [6]mythic [7]ultra [8]super）：";
  int equip_level;
  cin >> equip_level;
  if (equip_level > 8 || equip_level < 0) {
    cout << "错误等级\n";
    return;
  }
  if (num[id[equip_petals]][equip_level] == 0) {
    cout << "没有该等级的该花瓣\n";
    return;
  }
  if (ussing[num_petals].first != 0) {
    num[id[ussing[num_petals].second]][ussing[num_petals].first]++;
  }
  ussing[num_petals].first = equip_level;
  ussing[num_petals].second = equip_petals;
  num[id[ussing[num_petals].second]][ussing[num_petals].first]--;
  cout << "装备成功！\n";
}

void changeing() {
  cout << "请问要将字体改为什么颜色（[1]黑 [2]白 [3]红）：";
  int color;
  cin >> color;
  switch (color) {
  case 1:
    switch (now_color) {
    case 2:
      system("color 20");
      break;
    case 8:
      system("color 80");
      break;
    case 9:
      system("color 90");
      break;
    case 10:
      system("color A0");
      break;
    case 14:
      system("color E0");
      break;
    default:
      system("color 07");
    }
    break;
  case 2:
    switch (now_color) {
    case 2:
      system("color 27");
      break;
    case 8:
      system("color 87");
      break;
    case 9:
      system("color 97");
      break;
    case 10:
      system("color A7");
      break;
    case 14:
      system("color E7");
      break;
    default:
      system("color 07");
    }
    break;
  case 3:
    switch (now_color) {
    case 2:
      system("color 24");
      break;
    case 8:
      system("color 84");
      break;
    case 9:
      system("color 94");
      break;
    case 10:
      system("color A4");
      break;
    case 14:
      system("color E4");
      break;
    default:
      system("color 07");
    }
    break;
  default:
    cout << "不存在的颜色（由于其他颜色可能使字看不清，故作者没加入，需要请联系"
            "作者）\n";
    return;
  }
  cout << "更改成功！\n";
}

void save() {
  ofstream out1("Data.ini");
  for (int i = 1; i <= now_petals_number; i++) {
    for (int j = 1; j <= 8; j++) {
      out1 << num[i][j] << ' ';
    }
  }
  out1 << craft << ' ' << bag << ' ' << reload << ' ' << spining << ' '
       << summoner << ' ' << now_craft << ' ' << now_bag << ' ' << now_reload
       << ' ' << now_spining << ' ' << now_summoner << ' ' << bubble << ' '
       << cifen << ' ';
  for (int i = 1; i <= bag; i++) {
    out1 << ussing[i].first << ' ';
    if (ussing[i].second != "")
      out1 << ussing[i].second << ' ';
    else
      out1 << "nothing" << ' ';
  }
  out1 << expp << ' ' << now << ' ' << dot << ' ' << now_place;
  cout << "保存成功！";
  flush(cout);
  return;
}

void read() {
  ifstream in1("Data.ini");
  if (!in1) {
    cout << "你必须要先有一个存档！！！\n" << endl;
    return;
  }
  for (int i = 1; i <= now_petals_number; i++) {
    for (int j = 1; j <= 8; j++) {
      in1 >> num[i][j];
    }
  }
  in1 >> craft >> bag >> reload >> spining >> summoner >> now_craft >>
      now_bag >> now_reload >> now_spining >> now_summoner >> bubble >> cifen;
  for (int i = 1; i <= bag; i++) {
    in1 >> ussing[i].first >> ussing[i].second;
    // cout<<ussing[i].first<<" "<<ussing[i].second<<endl;
  }
  in1 >> expp >> now >> dot >> now_place;
  cout << "Loading...";
  Sleep(500);
  // Pause();
  cls();
  cout << "读取成功！\n";
  Sleep(500);
  return;
}

void change_size() {
  cout << "请问要切换到哪个大小？（默认为大）（[1]小 [2]中 [3]大）";
  int screen_size;
  cin >> screen_size;
  if (screen_size == 1) {
    system("mode con cols=52 lines=15");
    cout << "更改成功\n";
  } else if (screen_size == 2) {
    system("mode con cols=78 lines=24");
    cout << "更改成功\n";
  } else if (screen_size == 3) {
    system("mode con cols=154 lines=36");
    cout << "更改成功\n";
  } else
    cout << "没有这个大小\n";
}

void easy_fighting_engine(const vector<string> &place) {
  cls();
  while (1) {
    for (auto mob : place) {
      int mob_level = 9 - (int)cbrt(mrand() % 729 + 1);
      int hit = rand() % 100;
      if (hit < mob_level) {
        cout << "你被一只 " << level[mob_level] << ' ' << mob
             << "击败了。RIP.\n";
        now_place = 1;
        return;
      }
      if (hit < 75) {
        continue;
      }
      int drop_num = mrand() % 3 + 1;
      while (drop_num--) {
        int drop_id = mrand() % now_petals_number + 1;
        int drop_level = max(1ull, min(8ull, mob_level + mrand() % 3 - 1));
        num[drop_id][drop_level]++;
        cout << "你击败了一只 " << level[mob_level] << ' ' << mob
             << "，并获得了一个 " << level[drop_level] << ' ' << petals[drop_id]
             << " \n";
      }
      cout << "要继续吗（[y]是 [n]否）？";
      char cont;
      cin >> cont;
      if (cont == 'n')
        return;
      cls();
    }
  }
}

void fighting() {
  //	switch (FIGHTING_ENGINE) {
  //	case EASY_FIGHTING_ENGINE:
  switch (now_place) {
  case 1:
    easy_fighting_engine(garden);
    break;
  case 2:
    easy_fighting_engine(desert);
    break;
  case 3:
    easy_fighting_engine(ocean);
    break;
  case 4:
    easy_fighting_engine(jungle);
    break;
  case 5:
    easy_fighting_engine(ant_hole);
    break;
  }
  //	case HARD_FIGHTING_ENGINE:
  //		//TODO
  //		break;
  //	}
}

signed main() {
  system("mode con cols=54 lines=30");
  num[31][1] = 5;
  cout << "|---------------florr.io模拟器1.0测试版--------------|\n";
  cout << "			    	作者：某粉佬MCYYDS...\n";
  cout << "是否开始？（[q]开始，[其他]退出）";
  char st;
  cin >> st;
  if (st != 'q')
    return 0;
  cls();
  for (int i = 1; i <= now_petals_number; i++)
    id[petals[i]] = i;
  for (int i = 5; i <= 170; i++)
    level_need_exp.push_back(level_need_exp[i - 1] * 1.085);
  cout << "要读取存档吗（[y]是 [n]否）？";
  char duqu;
  cin >> duqu;
  Sleep(100);
  if (duqu == 'y') {
    read();
  }
  cls();
  cout << "要听背景故事吗（[y]是 [n]否）：";
  char story;
  cin >> story;
  Sleep(100);
  if (story == 'y') {
    vector<string> stories = {
        "在遥远的floyrd大陆上...", ".", "..", "...", ".", "..", "...",
        "好吧，其实没故事"};
    for (auto story : stories) {
      cout << story << endl;
      if (story == "好吧，其实没故事") {
        Sleep(2000);
        break;
      }
      Sleep(600);
      cls();
    }
  }
  cls();
  cout << "要听新手教程吗（[y]是 [n]否）：";
  char helping;
  cin >> helping;
  Sleep(100);
  if (helping == 'y') {
    cout << "这个游戏很简单的啦！\n只要不断刷怪，点技能，合成就能成功！\n最终目"
            "标是一套super装！\n";
    Pause();
  }
  refresh_map();
  cls();
  now_color = 10;
  system("mode con cols=154 lines=36");
  while (1) {
    cout << "请问现在要干什么：\n";
    cout << "[0]（新增）百科全书 [1]去其他地方 [2]查看物品栏 "
            "[3]点技能 [4]合成 [5]销毁（获得经验值） [6]攻击生物 [7]装备花瓣 "
            "[8]更改字体颜色 [9]调整大小 [10]退出\n";
    int op;
    cin >> op;
    switch (op) {
    case 0:
      dictionary();
      break;
    case 1:
      going();
      break;
    case 2:
      finding();
      break;
    case 3:
      skilling();
      break;
    case 4:
      crafting();
      break;
    case 5:
      absorbing();
      break;
    case 6:
      fighting();
      break;
    case 7:
      equiping();
      break;
    case 8:
      changeing();
      break;
    case 9:
      change_size();
      break;
    case 10:
      cout << "要保存存档吗（[y]是 [n]否）？";
      char baocun;
      cin >> baocun;
      if (baocun == 'y') {
        save();
      }
      return 0;
    case 114514:
      cout << "进入开发者模式\n";
      cout << "增加多少个技能点：\n";
      int add_dot;
      cin >> add_dot;
      dot += add_dot;
      cout << "请问要将什么等级的什么花瓣增加多少个，退出请输0\n";
      while (1) {
        int dev_op;
        cin >> dev_op;
        if (dev_op == 0)
          break;
        string petals;
        cin >> petals;
        int p_num;
        cin >> p_num;
        num[id[petals]][dev_op] += p_num;
      }
      break;
    default:
      cout << "没有该选项";
    }
    if (cifen) {
      cout << "你现在有" << cifen << "个磁粉，快叫薛皓文来看看！！！\n";
    }
    Pause();
    cls();
    refresh_map();
  }
  return 0;
}
