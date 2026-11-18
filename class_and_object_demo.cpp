py-面向对象学习的代码
# 定义冰箱
# 构造方法：创建冰箱对象时自动执行，初始化属性
def __init__(self, brand):
self.brand = brand   # 实例属性：冰箱品牌
self.inside = []     # 实例属性：冰箱内部，存放东西的空间
# 实例方法：把东西放进去，是冰箱的行为(在这个过程中会出现封装-对象之外的信息不会出现)
def put_in(self, thing):
self.inside.append(thing)
print(f"操作：把【{thing}】放进{self.brand}冰箱")
# 实例方法：查看冰箱里面有什么
def show_what_in(self):
print(f"{self.brand}冰箱内物品：{self.inside}")
# 实例方法：拿出东西
def take_out(self, thing):
if thing in self.inside:
self.inside.remove(thing)
print(f"操作：把【{thing}】从冰箱取出来")
else:
print(f"【{thing}】不在冰箱里！")
if __name__ == '__main__':
# 实例化：创建一个冰箱对象
my_fridge = Fridge("美的")
# 调用方法：把cy放进冰箱
my_fridge.put_in("cy")
# 调用方法：查看冰箱内部
my_fridge.show_what_in()
# 调用方法：把cy拿出来
my_fridge.take_out("cy")
my_fridge.show_what_in()
在这个代码中我没有直接用cy,而是用的thing先泛指了一类事物,这样对于具有同样特征的不用再输入一遍,就可以轻松地解决.
如果想要全部改变的话就用快捷键Ctrl + H，在替换框中查找：cy  替换为：lwp;如果要改变一个地方if __name__ == '__main__':
name = "lwp"即可
要把冰箱换成其他的,比如洗衣机class Fridge:改为class Washingmachine;my_fridge = Fridge("美的")改为my_Washingmachine =Washingmachine ("海尔");
my_fridge.改为my_Washingmachine
cpp-面向对象学习的代码
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 定义冰箱
class Fridge
{
public:
// 构造函数：创建冰箱对象自动调用，初始化品牌
Fridge(string b)
{
brand = b;
}
// 成员函数：放入物品(内容同上)
void put_in(string thing)
{
inside.push_back(thing);
cout << "操作：把【" << thing << "】放进" << brand << "冰箱" << endl;
}
// 成员函数：查看里面所有物品
void show_what_in()
{
cout << brand << "冰箱内物品：";
for(auto &x : inside){
cout << x << " ";
}
cout << endl;
}
// 成员函数：取出物品
void take_out(string thing)
{
for(auto it = inside.begin(); it != inside.end(); it++)
{
if(*it == thing)
{
inside.erase(it);
cout << "操作：把【" << thing << "】从冰箱取出来" << endl;
return;
}
}
cout << "【" << thing << "】不在冰箱里！" << endl;
}
private:
string brand;          // 私有属性：冰箱品牌，外部不能直接修改
vector<string> inside; // 私有属性：冰箱内部存储空间
};
int main()
{
// 实例化冰箱对象
Fridge my_fridge("美的");
my_fridge.put_in("cy");
my_fridge.show_what_in();
my_fridge.take_out("cy");
my_fridge.show_what_in();
-return 0;
}
################################################################################
// 封装：数据 private，读写走 public 方法
class cy {
public:
std::string 取名字() const;           // getter：读私有属性
void 改体积(int 新体积) {             // setter：写私有属性，校验写在这里
if (新体积 > 0) 体积_ = 新体积;    // 规则：体积必须大于 0
}
private:
std::string 名字_;                    // 对象属性：外界碰不到
int 体积_ = 1;
};
一个.体积_ = 0;                           // 编译报错：private 不可访问
一个.改体积(-1);                          // 编译通过，但被校验拦下
// 继承：共同点在父类，子类只补差异
class 实物 {                              // 父类：有体积、能被塞
public:
explicit 实物(int 体积) : 体积_(体积) {}   // 构造函数 + 初始化列表
int 取体积() const;
protected:
int 体积_;                            // 子类可访问，外界不行
};
class cy : public 实物 {                // 公有继承：cy是个人 
public:
cy() : 实物(4) {}                   // 只补差异：固定体积
int 身高178cm_;                            // 大象特有属性
};
class lwp : public 实物 {                // 加lwp只新增几行
public:
lwp() : 实物(1) {}
};
// 多态：同一句调用，跑出不同结果
class 容器 {
public:
virtual void 开门();                  // virtual：允许子类重写
virtual ~容器() = default;            // 虚析构：基类指针/引用删除对象的标配
};
class 冰箱 : public 容器 {
public:
void 开门() override;                 // override：显式标注重写，开门亮灯
};
class 洗衣机 : public 容器 {
public:
void 开门() override;                 // 开门先停转
};
void 塞三步(容器& 某) {                   // 主流程只认「容器」（向上转型）
    某.开门();                            // 动态绑定：运行时决定调谁的开门()
    某.塞入();
    某.关门();
}
冰箱 一台冰箱;
洗衣机 一台洗衣机;
塞三步(一台冰箱);                         // 跑冰箱的开门()
塞三步(一台洗衣机);                       // 跑洗衣机的开门()
// 抽象：纯虚函数 = 只有约定，没有实现
class 容器 {
public:
virtual void 开门() = 0;              // 纯虚函数：容器成为抽象类
virtual ~容器() = default;
};
容器 一个;                                // 编译报错：抽象类不能实例化
class 烤箱 : public 容器 {
public:
void 开门() override;                 // 必须实现开门()，否则烤箱也是抽象类
};
// 接口：全部成员都是纯虚函数的类
class 能塞 {
public:
virtual bool 塞入(const 实物& 某物) = 0;
virtual ~能塞() = default;
};
