import pandas as pd

person_columns = ["ID", "姓名", "状态"]
record_columns = ["ID", "Time", "Temperature", "BOL"]

person_df = pd.DataFrame(columns=person_columns)
record_df = pd.DataFrame(columns=record_columns)

funcs = {}  # 用来存储所有功能的字典


def decorator(func):
    funcs[func.__name__] = func
    return func


@decorator
def add_person():
    id = int(input("请输入ID: "))
    name = input("请输入姓名: ")
    status = input("请输入当前状况 (阴/阳/阳康): ")

    duplicate_id = person_df["ID"].isin([id]).any()
    duplicate_name = person_df['姓名'].isin([name]).any()

    if not duplicate_id and not duplicate_name:
        new_row = {"ID": id, "姓名": name, "状态": status}
        person_df.loc[len(person_df)] = new_row
        print("数据已成功插入。")
    else:
        print("错误：数据已存在，不能重复插入。")


@decorator
def update_person():
    id = int(input("请输入要修改的人员ID: "))
    duplicate_id = person_df["ID"].isin([id]).any()

    if not duplicate_id:
        print("没有该ID的信息")
        return

    name = input("请输入新姓名 (保持原名则直接回车): ")
    status = input("请输入新状况 (保持原状则直接回车): ")

    if name != "":
        person_df.loc[person_df["ID"] == id, "姓名"] = name
    if status != "":
        person_df.loc[person_df["ID"] == id, "状态"] = status
    print("信息已成功更新")


@decorator
def add_record():
    id = int(input("请输入人员ID: "))
    time = input("请输入时间戳: ")
    temperature = float(input("请输入体温: "))
    BOL = int(input("请输入血氧值: "))

    new_row = {"ID": id, "Time": time, "Temperature": temperature, "BOL": BOL}
    record_df.loc[len(record_df)] = new_row
    print("记录已成功添加")


@decorator
def query_person():
    id = int(input("请输入要查询的人员ID: "))
    person_row = person_df.loc[person_df["ID"] == id]

    if len(person_row) == 0:
        print("没有该ID的信息")
    else:
        print(f"人员信息:\n{person_row.to_string(index=False)}")


@decorator
def query_record():
    id = int(input("请输入要查询的人员ID: "))
    record_rows = record_df.loc[record_df["ID"] == id]

    if len(record_rows) == 0:
        print("没有该ID的记录")
    else:
        print(f"体温血氧记录:\n{record_rows.to_string(index=False)}")


def main_menu():
    print("\n请选择功能：")
    sorted_funcs = sorted(funcs.keys())
    for idx, func in enumerate(sorted_funcs):
        print(f"{idx + 1} - {func}")

    option = input("请输入功能对应的数字(q退出): ")
    return option


def run_option(option):
    if option.isdigit():
        idx = int(option) - 1
        sorted_funcs = sorted(funcs.keys())
        if 0 <= idx < len(sorted_funcs):
            func_key = sorted_funcs[idx]
            funcs[func_key]()


while True:
    option = main_menu()

    if option in ("q", "Q"):
        print("\n谢谢使用！再见！")
        break

    run_option(option)

