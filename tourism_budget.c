#include "tourism_budget.h"
#include "tourism_budget_util.h"


int way_judge(int now, double current_tank) {
    //表示当前达到最后一个站点
    if (now == num)
        return (current_tank
                > (distance - stations[now]->length) / consume)
               ? 1 : 2;
    else {
        if (current_tank > (stations[now + 1]->length - stations[now]->length) / consume)
            return (current_tank
                    > capacity / 2)
                   ? 1 : 3;
        else return 2;
    }
}

void dfs(int past, int now, double money, double current_tank, int book[]) {
    //剪枝:剪去所有在过程中就比存储下来的值小的路径
    if (money > MIN_BUDGET) return;
    //达到结束条件
    if (now > num) {
        if (money < MIN_BUDGET) {
            MIN_BUDGET = money;
            int i;
            for (i = 0; i <= num; i++) {
                vis[i] = book[i];
                book[i] = 0;
            }
        }
        return;
    }

    //计算距离上次加油和现在站点的距离
    double new_distance = stations[now]->length - stations[past]->length;
    //计算到当前站点车剩余油量
    double new_current_tank = capacity - new_distance / consume;
    //剪枝:剪去在过程中出现油箱为空的情况
    if (new_current_tank > 0) {
        //获取加油的策略
        int status = way_judge(now, new_current_tank);
        if (status == 1) {
            now++;
            dfs(past, now, money, new_current_tank, book);
            now--;
        } else if (status == 2) {
            money += ((new_distance / consume) * stations[now]->price + 2);
            int temp_now = now;
            now++;
            book[temp_now] = 1;
            dfs(temp_now, now, money, current_tank, book);
            now--;
            money -= ((new_distance / consume) * stations[now]->price + 2);
        } else if (status == 3) {
            now++;
            dfs(past, now, money, new_current_tank, book);
            now--;

            money += ((new_distance / consume) * stations[now]->price + 2);
            int temp_now = now;
            now++;
            book[temp_now] = 1;
            dfs(temp_now, now, money, current_tank, book);
            now--;
            money -= ((new_distance / consume) * stations[now]->price + 2);
        }
    } else return;
}

//初始化操作
void init() {
    //初始化最小花费
    MIN_BUDGET = MAX_NUM;
    //给指针分配空间
    int i;
    for (i = 0; i <= 50; i++)
        stations[i] = (Station) malloc(sizeof(Station));
    stations[0]->price = 0.0;
    stations[0]->length = 0.0;
    //读取文件
    file_read();
    //初始化路径为0
    int book[51];
    memset(vis, 0, sizeof(vis));
    memset(book, 0, sizeof(book));
    //深搜
    dfs(0, 1, 0, capacity, book);
    //最后要加上初始的消费
    MIN_BUDGET += cost;
}

void destroy() {
    int i;
    for (i = 0; i <= 50; i++)
        free(stations[i]);
    file_close();
}

void start() {
    init();
    file_write();
    destroy();
}

int main() {
    start();
    return 0;
}