import pandas as pd
person_columns = ["ID","姓名","状态"]
person_data = []
person_df = pd.DataFrame(person_data,columns=person_columns)

record_columns = ["ID","Time","Temperature","BOL"]
record_data = []
record_df = pd.DataFrame(record_data,columns=record_columns)

def add_person(id, name, status):
    data = {"ID": id, "姓名": name, "状态": status}

    # 判断新插入的数据是否重复
    duplicate_id = person_df["ID"].isin([id]).any()
    duplicate_name = person_df['姓名'].isin([name]).any()

    # 如果未发现重复数据，则插入新数据
    if not duplicate_id and not duplicate_name:
        person_df.loc[len(person_df)] = data
        print("数据已成功插入。")
    else:
        print("错误：数据已存在，不能重复插入。")

def update_person(id, name, status):
    duplicate_id = person_df["ID"].isin([id]).any()
    if not duplicate_id:
        print("没有该ID的信息")
    else:
        if name is not None:
            person_df.loc[person_df["ID"]==id,"姓名"] = name
        if status is not None:
            person_df.loc[person_df["ID"]==id,"状态"] = status

def find_person(id):
    duplicate_id = person_df["ID"].isin([id]).any()
    if not duplicate_id:
        print("没有该ID的信息")
    else:
        print(person_df.loc[person_df["ID"]==id])

def add_record(id,time,temperature,BOL):
    data = {"ID": id, "Time": time, "Temperature": temperature,"BOL":BOL}
    record_df.loc[len(record_df)] = data

def find_record(id):
    duplicate_id = record_df["ID"].isin([id]).any()
    if not duplicate_id:
        print("没有该ID的信息")
    else:
        max_temp = record_df.loc[record_df["ID"]==id,"Temperature"].max()
        min_BOL = record_df.loc[record_df["ID"]==id,"BOL"].min()
        print(f"最高体温：{max_temp}\n最低血氧值：{min_BOL}")


# 主函数
def main():
    while True:
        print("请选择功能：")
        print("1 - 录入人员信息")
        print("2 - 修改人员信息")
        print("3 - 查看某个人员信息")
        print("4 - 查看所有人员的基本信息")
        print("5 - 录入体温血氧监测记录")
        print("6 - 查看某个人员的所有体温血氧监测记录")
        print("7 - 查看某个人员的最高体温、最低血氧等")
        print("8 - 将人员信息和体温血氧记录保存为文件")
        print("0 - 退出程序")
        choice = input("请输入对应的数字: ")

        if choice == '1':
            id = int(input("请输入 id: "))
            name = input("请输入姓名: ")
            status = input("请输入当前状况 (阴/阳/阳康): ")
            add_person(id, name, status)

        elif choice == '2':
            id = int(input("请输入要修改的人员 id: "))
            name = input("请输入新姓名 (保持原名则直接回车): ")
            status = input("请输入新状况 (保持原状则直接回车): ")
            name = None if name == "" else name
            status = None if status == "" else status
            update_person(id, name, status)

        elif choice == '3':
            id = int(input("请输入要查找的人员id: "))
            find_person(id)

        elif choice == '4':
            print(person_df)

        elif choice == '5':
            id = int(input("请输入人员 id: "))
            time = input("请输入时间戳: ")
            temperature = float(input("请输入体温: "))
            BOL = int(input("请输入血氧值: "))
            add_record(id, time, temperature, BOL)

        elif choice == '6':
            id = int(input("请输入人员 id: "))
            print(record_df[record_df["ID"]==id])

        elif choice == '7':
            id = int(input("请输入人员 id: "))
            find_record(id)

        elif choice == '8':
            person_df.to_csv("person_df",index=False,encoding="utf-8")
            record_df.to_csv("record_df",index=False,encoding="utf-8")
            print("保存成功")

        elif choice == '0':
            print("谢谢使用！再见！")
            break

        else:
            print("输入错误，请重新输入！")

if __name__ == "__main__":
    main()
