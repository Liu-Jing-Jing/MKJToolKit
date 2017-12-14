//
//  main.cpp
//  DataStructure_FinalPrioject
//  SportsAchievementManager.c
//  Created by Mark Lewis on 17-12-13.
//  Copyright (c) 2017年 Mark Lewis. All rights reserved.
//
#include "SportsAchievementManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <fstream.h>

#define passcodeTxtFilePath "/Users/Mark/Developer/Projects/Xcode9 Project/DataStructureDemo/DataStructureDemo/password.txt"
#define gameDataTxtFilePath "/Users/Mark/Developer/Projects/Xcode9 Project/DataStructureDemo/DataStructureDemo/game_data.txt"
#define departmentTxtFilePath "/Users/Mark/Developer/Projects/Xcode9 Project/DataStructureDemo/DataStructureDemo/department_data.txt"
typedef struct athlete
{
    char name[20];  //姓名
    char code[10]; //号码
    char department[20]; //院系
}Athlete;

typedef struct award_name
{
    char sport[20]; //项目名称
    char sex[10];       //f女 m男
    Athlete award_ath;
    int rank;
    int score;
}Award;

typedef struct statistic
{
    char department[20];
    int score_fm;
    int score_m;
    int score;
}Statistic;

int JudgePassword()
{
    char inp[20];
    char p[20];
    FILE *fp = NULL;
    fp = fopen(passcodeTxtFilePath, "r+");
    fscanf(fp, "%s", p);
    // if(strcmp(p, "******") == 0)      //输入原始密码
    if(strcmp(p, "******"))
    {
        printf("Please input init password (no more than 15ch)\n");
        scanf("%s", p);
        fprintf(fp, "%s", p);
        fclose(fp);
        return 1;
    }
    else
    {
        printf("Please input the password\n");
        scanf("%s", inp);
        if(strcmp(inp, p + 6) == 0)
        {
            fclose(fp);
            return 1;
        }
        else
        {
            printf("wrong password!\n");
            fclose(fp);
            return 0;
        }
    }
}

void inputResult()
{
    int i;// j
    int d_num = 0, a_num = 0;
    //int tmpd, tmpa;
    //int flag1, flag2,
    FILE *fp1, *fp2;
    Award a[3], af[100];
    Statistic s[3], sf[100];
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    fp1 = fopen(gameDataTxtFilePath, "r");
    fp2 = fopen(departmentTxtFilePath, "r");
    fscanf(fp2, "%d\n", &d_num);
    fscanf(fp1, "%d\n", &a_num);
    for(i = 0; i < d_num; i++)
        fscanf(fp2, "%s %d %d %d\n", sf[i].department, &sf[i].score_fm, &sf[i].score_m, &sf[i].score);
    for(i = 0; i < a_num; i++)
        fscanf(fp1, "%s %s %s %s %s %d %d\n", af[i].sport, af[i].award_ath.name, af[i].award_ath.code, af[i].award_ath.department, af[i].sex, &af[i].rank, &af[i].score);
    fclose(fp1);
    fclose(fp2);
    printf("按项目输入前三名信息(项目名称 姓名 编号 院系 性别 排名):\n");
    for(i = 0; i < 3; i++)
    {
        scanf("%s %s %s %s %s %d", a[i].sport, a[i].award_ath.name, a[i].award_ath.code, a[i].award_ath.department, a[i].sex, &a[i].rank);
        if(i == 0)
        {
            if(a[i].sex[0] == 'f')
                s[i].score_fm += 7;
            else
                s[i].score_m += 7;
            s[i].score += 7;
            a[i].score += 7;
        }
        else if(i == 1)
        {
            if(a[i].sex[0] == 'f')
                s[i].score_fm += 5;
            else
                s[i].score_m += 5;
            s[i].score += 5;
            a[i].score += 5;
        }
        else if(i == 2)
        {
            if(a[i].sex[0] == 'f')
                s[i].score_fm += 4;
            else
                s[i].score_m += 4;
            s[i].score += 4;
            a[i].score += 4;
        }
        strcpy(s[i].department, a[i].award_ath.department);
    }
    for(i = 0; i < 3; i++)
    {
        af[a_num + i] = a[i];
        sf[d_num + i] = s[i];
    }
    a_num += 3;
    d_num += 3;
    fp1 = fopen(gameDataTxtFilePath, "w");
    fp2 = fopen(departmentTxtFilePath, "w");
    fprintf(fp2, "%d\n", d_num);
    fprintf(fp1, "%d\n", a_num);
    for(i = 0; i < a_num; i++)
        fprintf(fp1, "%s %s %s %s %s %d %d\n", af[i].sport, af[i].award_ath.name, af[i].award_ath.code, af[i].award_ath.department, af[i].sex, af[i].rank, af[i].score);
    for(i = 0; i < d_num; i++)
        fprintf(fp2, "%s %d %d %d\n", sf[i].department, sf[i].score_fm, sf[i].score_m, sf[i].score);
    fclose(fp1);
    fclose(fp2);
}

void Swap(Statistic x, Statistic y)
{
    Statistic tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void Sort(Statistic *s, int num, int op) //0总分 1男 2女
{
    int i, j, mi, idx;
    for(i = 0; i < num; i++)
    {
        mi = 1000000;
        for(j = i; j < num; j ++)
        {
            if(op == 0)
            {
                if(s[j].score < mi)
                {
                    mi = s[j].score;
                    idx = j;
                }
            }
            else if(op == 1)
            {
                if(s[j].score_m < mi)
                {
                    mi = s[j].score_m;
                    idx = j;
                }
            }
            else
            {
                if(s[j].score_fm < mi)
                {
                    mi = s[j].score_fm;
                    idx = j;
                }
            }
        }
        Swap(s[i], s[j]);
    }
}

void outputTotalGoal()
{
    int i, j, num, cnt = 0, flag = 0, idx = 0;
    
    Statistic s[100], rs[100];
    FILE *fp;
    memset(rs, 0, sizeof(rs));
    fp = fopen(departmentTxtFilePath, "r");
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %d %d %d\n", s[i].department, &s[i].score_fm, &s[i].score_m, &s[i].score);
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < cnt; j++)
        {
            flag = 0;
            if(strcmp(s[i].department, rs[j].department) == 0)
            {
                flag = 1;
                idx = j;
                break;
            }
        }
        if(flag)
        {
            rs[idx].score += s[i].score;
        }
        else
        {
            strcpy(rs[cnt].department, s[i].department);
            rs[cnt].score += s[i].score;
            cnt ++;
        }
    }
    Sort(rs, cnt, 0);
    for(i = 0; i < cnt; i++)
        printf("院系名称: %s  总分: %d\n", rs[i].department, rs[i].score);
    fclose(fp);
}

void outputFandfmGoal()
{
    int i, j, num, cnt1 = 0, cnt2 = 0, f1 = 0, f2 = 0, idx = 0;
    Statistic s[100], rfs[100], rms[100];
    FILE *fp;
    fp = fopen(departmentTxtFilePath, "r");
    memset(rfs, 0, sizeof(rfs));
    memset(rms, 0, sizeof(rms));
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %d %d %d\n", s[i].department, &s[i].score_fm, &s[i].score_m, &s[i].score);
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < cnt1; j++)
        {
            f1 = 0;
            if(strcmp(s[i].department, rms[j].department) == 0)
            {
                f1 = 1;
                idx = j;
                break;
            }
        }
        if(f1)
        {
            rms[idx].score_m += s[i].score_m;
            //printf("rms[%d].score_m = %d\n", idx, rms[idx].score_m);
        }
        else
        {
            //printf("rms[%d].score_m = %d\n", cnt1, rms[cnt1].score_m);
            strcpy(rms[cnt1].department, s[i].department);
            rms[cnt1].score_m += s[i].score_m;
            cnt1 ++;
        }
    }
    Sort(rms, cnt1, 1);
    for(i = 0; i < cnt1; i++)
        printf("院系名称: %s  男团分: %d\n", rms[i].department, rms[i].score_m);
    printf("\n\n");
    for(i = 0; i < num; i++)
    {
        for(j = 0; j < cnt2; j++)
        {
            f2 = 0;
            if(strcmp(s[i].department, rfs[j].department) == 0)
            {
                f2 = 1;
                idx = j;
                break;
            }
        }
        if(f2)
            rfs[idx].score_fm += s[i].score_fm;
        else
        {
            strcpy(rfs[cnt2].department, s[i].department);
            rfs[cnt2].score_fm += s[i].score_fm;
            cnt2 ++;
        }
    }
    Sort(rfs, cnt2, 2);
    for(i = 0; i < cnt2; i++)
        printf("院系名称: %s  女团分: %d\n", rfs[i].department, rfs[i].score_fm);
    fclose(fp);
}

void queryByDepartment()
{
    int i, num, flag = 0, sum = 0, fm_sum = 0, m_sum = 0;
    FILE *fp;
    Statistic s[20];
    char d_name[100];
    fp = fopen(departmentTxtFilePath, "r");
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %d %d %d\n", s[i].department, &s[i].score_fm, &s[i].score_m, &s[i].score);
    printf("请输入查询的院系名称:\n");
    scanf("%s", d_name);
    for(i = 0; i < num; i++)
    {
        if(strcmp(d_name, s[i].department) == 0)
        {
            flag = 1;
            sum += s[i].score;
            m_sum += s[i].score_m;
            fm_sum += s[i].score_fm;
        }
    }
    if(!flag)
        printf("没有该院系的相关信息\n");
    else
        printf("院系名称: %s\n", d_name);
    printf("总分: %d\n", sum);
    printf("男子总分: %d\n", m_sum);
    printf("女子总分: %d\n", fm_sum);
    fclose(fp);
}

void queryByProjectName()
{
    int i, num, flag = 0, cnt = 0;
    FILE *fp;
    Award ad[100], Tar[100];
    char a_name[100];
    memset(Tar, 0, sizeof(Tar));
    fp = fopen(gameDataTxtFilePath, "r");
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %s %s %s %s %d %d\n", ad[i].sport, ad[i].award_ath.name, ad[i].award_ath.code, ad[i].award_ath.department, ad[i].sex, &ad[i].rank, &ad[i].score);
    printf("请输入查询的项目名称:\n");
    scanf("%s", a_name);
    for(i = 0; i < num; i++)
    {
        if(strcmp(a_name, ad[i].sport) == 0)
        {
            flag = 1;
            Tar[cnt ++] = ad[i];
        }
    }
    if(!flag)
        printf("没有该项目的相关信息\n");
    else
    {
        printf("项目名称: %s\n", a_name);
        for(i = 0; i < cnt; i++)
        {
            printf("运动员姓名: %s  编号: %s  学院: %s\n", Tar[i].award_ath.name, Tar[i].award_ath.code, Tar[i].award_ath.department);
            printf("运动员性别: %s  得分: %d  排名: %d\n", Tar[i].sex, Tar[i].score, Tar[i].rank);
            printf("\n");
        }
    }
    fclose(fp);
}

int AdminOpt() //管理员选项
{
    int opt = 0;
    printf("请选择操作\n");
    printf("1 - 填写比赛结果\n");
    printf("2 - 输出学院总分\n");
    printf("3 - 输出男子团体，女子团体的总分\n");
    printf("4 - 按院系名称查询比赛成绩\n");
    printf("5 - 按运动项目名称查询比赛成绩\n");
    printf("6 - 退出\n");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
            inputResult();
            break;
        case 2:
            outputTotalGoal();
            break;
        case 3:
            outputFandfmGoal();
            break;
        case 4:
            queryByDepartment();
            break;
        case 5:
            queryByProjectName();
            break;
        case 6:
            return 0;
    }
    return 1;
}

void queryByPerson()
{
    int i, num, flag = 0, cnt = 0;
    FILE *fp;
    Award ad[100], Tar[100];
    char p_name[100];
    memset(Tar, 0, sizeof(Tar));
    fp = fopen(gameDataTxtFilePath, "r");
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %s %s %s %s %d %d\n", ad[i].sport, ad[i].award_ath.name, ad[i].award_ath.code, ad[i].award_ath.department, ad[i].sex, &ad[i].rank, &ad[i].score);
    printf("请输入查询的运动员姓名:\n");
    scanf("%s", p_name);
    for(i = 0; i < num; i++)
    {
        if(strcmp(p_name, ad[i].award_ath.name) == 0)
        {
            flag = 1;
            Tar[cnt ++] = ad[i];
        }
    }
    if(!flag)
        printf("没有该运动员的相关信息\n");
    else
    {
        printf("姓名: %s  编号: %s  学院: %s  性别: %s\n", p_name, Tar[0].award_ath.code, Tar[0].award_ath.department, Tar[0].sex);
        for(i = 0; i < cnt; i++)
            printf("项目名称: %s  得分: %d  排名: %d\n", Tar[i].sport, Tar[i].score, Tar[i].rank);
    }
    fclose(fp);
}

/*
 函数的功能是: 普通用户来查询最终得分
 */
void userQueryFinalRank()
{
    int i, num, flag = 0, cnt = 0;
    FILE *fp;
    Award ad[100], Tar[100];
    char s_name[100];
    fp = fopen(gameDataTxtFilePath, "r");
    fscanf(fp, "%d", &num);
    for(i = 0; i < num; i++)
        fscanf(fp, "%s %s %s %s %s %d %d\n", ad[i].sport, ad[i].award_ath.name, ad[i].award_ath.code, ad[i].award_ath.department, ad[i].sex, &ad[i].rank, &ad[i].score);
    printf("请输入查询的项目名称:\n");
    scanf("%s", s_name);
    for(i = 0; i < num; i++)
    {
        if(strcmp(s_name, ad[i].sport) == 0)
        {
            flag = 1;
            Tar[cnt ++] = ad[i];
        }
    }
    if(!flag)
        printf("没有该项目的相关信息\n");
    else
    {
        printf("项目名称: %s\n", Tar[0].sport);
        for(int i = 0; i < cnt; i++)
        {
            printf("姓名: %s  编号: %s  学院: %s\n",  Tar[i].award_ath.name, Tar[i].award_ath.code, Tar[i].award_ath.department);
            printf("性别: %s  得分: %d  排名: %d\n", Tar[i].sex, Tar[i].score, Tar[i].rank);
            printf("\n");
        }
    }
    fclose(fp);
}

// 普通用户的公共操作
int userOption()
{
    int opt = 0;
    printf("请选择操作\n");
    printf("1 - 查询运动员个人比赛成绩\n");
    printf("2 - 查看参赛院系的成绩\n");
    printf("3 - 各比赛项目最终名次\n");
    printf("4 - 退出\n");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
            queryByPerson();
            break;
        case 2:
            queryByDepartment();
            break;
        case 3:
            userQueryFinalRank();
            break;
        case 4:
            return 0;
    }
    return 1;
}

int SportsManagerRuns()
{
    system("color d1");
    printf("组长 科文老司机");
    
    char id[20];    //管理员or用户
    printf("You can enter Q to quit\n\nPlease enter admin or user\n");
    while(scanf("%s", id))
    {
        if(strcmp(id, "admin") == 0)
        {
            // while(!JudgePassword());
            while(AdminOpt());
            exit(0);
        }
        else if(strcmp(id, "user") == 0)
        {
            while(userOption());
            exit(0);
        }
        else if(strcmp(id, "Q") == 0)
        {
            exit(0);
        }
        else
        {
            printf("invalid input\n");
        }
    }
    return 0;
}
//
//int main(int argc, const char * argv[])
//{
//
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
