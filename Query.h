//
// Created by 18012 on 2023/4/15.
//

#ifndef AIRSYSTEM_QUERY_H
#define AIRSYSTEM_QUERY_H
void QueryByOrderid();//按订单编号查询
void QueryByName();//按用户名查询
void QueryBySeatAvailble();//按空余座位查询
void QueryByDate();//按航班日期查询
void QueryByStart();//按出发地查询
void QueryByEnd();//按到达地查询
void SortByStart();//按出发时间排序
void SortByPrice();//按价格排序
void CountNumber();//统计乘坐次数
#endif //AIRSYSTEM_QUERY_H
