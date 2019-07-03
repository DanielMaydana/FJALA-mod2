#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

// ----------------COL_ENUM----------------

enum class col
{
  string,
  integer,
  def
};

// ----------------COLUMN_INFO----------------

class column_info
{
  string col_name;
  col type;

public:
  column_info(const string &col_name, col type)
      : col_name{col_name}, type{type}
  {
  }

  string &get_name()
  {
    return col_name;
  }

  col &get_type()
  {
    return type;
  }
};

// ----------------CELL----------------

template <typename C>
struct cell
{
  C val;

  cell(const C &val) : val{val}
  {
  }
};

template <>
struct cell<string>
{
  string val;

  cell(const string &val) : val{val}
  {
  }

  string as_string()
  {
    return val;
  }
};

template <>
struct cell<int>
{
  int val;

  cell(const int &val) : val{val}
  {
  }

  string as_string()
  {
    return to_string(val);
  }
};

// ----------------ROW----------------

struct row
{
  // TODO: find a better way to contain different types in a single container
  vector<string> str_elems; // maybe not the best way
  vector<int> int_elems;    // maybe not the best way
  vector<col> types;

  cell<int> operator[](const string &col_name)
  {
    // TODO: return a propper cell according to its col name
    return cell<int>{0};
  }

  bool has_value() const
  {
    // TODO: evaluate properly if row has content
    return false;
  }

  row &get_row()
  {
    return *this;
  }
};

// ----------------TABLE----------------
class table
{
  string tb_name;
  vector<column_info> col_info;
  size_t row_count;
  size_t col_count;

  vector<row> all_rows;

public:
  table(const string &tb_name)
      : tb_name{tb_name}, row_count{0}, col_count{0}
  {
  }

  string &get_name()
  {
    return tb_name;
  }

  template <typename T>
  void add_columns(const T &info)
  {
    col_count++;
    col_info.push_back(info);
  }

  template <typename T, typename... ARGS>
  void add_columns(const T &info, const ARGS &... args)
  {
    add_columns(info);
    add_columns(args...);
  }

  template <typename U>
  void add_row_recursive(const U &cell)
  {
    // cout << "|" << cell << "|\n";
    // TODO: push a single cell to a specific row
    // last step in the recursive function
  }

  template <typename U, typename... ARGS>
  void add_row_recursive(const U &cell, const ARGS &... args)
  {
    add_row_recursive(cell);
    add_row_recursive(args...);
  }

  template <typename U, typename... ARGS>
  void add_row(const U &cell, const ARGS &... args)
  {
    row_count++;
    row aux_row{};
    add_row_recursive(cell, args...);
  }

  auto &get_columns()
  {
    return col_info;
  }

  column_info &get_column_by_name(const string &col_name)
  {
    for (auto &single_col_info : col_info)
    {
      if (col_name == single_col_info.get_name())
        return single_col_info;
    }
  }

  size_t get_row_count()
  {
    return row_count;
  }

  vector<row> &get_all_rows()
  {
    return all_rows;
  }

  vector<row> filter_rows(bool (*search)(row &row))
  {
    // TODO: filter properly according to lambda criteria
    return vector<row>{};
  }

  bool contains_by_id(const int &id)
  {
    // TODO: search a row properly by the id
    return false;
  }

  void delete_by_id(const int &id)
  {
    // TODO: delete a row properly by the id
  }

  row get_by_id(const string &id)
  {
    // TODO: return a row according to an id (string)
    return row{};
  }

  row get_by_id(const int &id)
  {
    // TODO: return a row according to an id (int)
    return row{};
  }

  void delete_rows(bool (*del_criteria)(row &row))
  {
    // TODO: delete a row according to some criteria
  }
};

// ----------------MEMORY_DB----------------

class memory_db
{
  string db_name;
  size_t tb_count;

  map<string, table *> all_tables;

public:
  memory_db(const string &db_name)
      : db_name{db_name}, tb_count{0}
  {
  }

  table &add_table(const string &tb_name)
  {
    tb_count++;
    table *t = new table{tb_name};
    all_tables.insert(make_pair(tb_name, t));
    return *t;
  }

  string &get_name()
  {
    return db_name;
  }

  size_t &get_table_count()
  {
    return tb_count;
  }

  table &operator[](const string &tb_name)
  {
    for (auto &t : all_tables)
    {
      if (t.first == tb_name)
        return *(t.second);
    }
  }
};

// -----------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------

bool test0()
{
  memory_db db{"college"};
  auto &stt = db.add_table("students");
  db.add_table("courses");

  return db.get_name() == "college" && stt.get_name() == "students" && db.get_table_count() == 2;
}

bool test1()
{
  memory_db db{"college"};
  auto &stt = db.add_table("students");
  stt.add_columns(column_info{"id", col::integer},
                  column_info{"first_name", col::string},
                  column_info{"last_name", col::string},
                  column_info{"birthyear", col::integer});

  auto &cot = db.add_table("courses");
  cot.add_columns(column_info{"id", col::string},
                  column_info{"name", col::string});

  return db["students"].get_columns().size() == 4 &&
         db["courses"].get_columns().size() == 2 &&
         db["courses"].get_column_by_name("id").get_type() == col::string;
}

bool test2()
{
  memory_db db{"college"};
  auto &stt = db.add_table("students");
  stt.add_columns(column_info{"id", col::integer},
                  column_info{"first_name", col::string},
                  column_info{"last_name", col::string},
                  column_info{"birthyear", col::integer});

  stt.add_row(1, "Juan", "Perez", 1980);
  stt.add_row(2, "Pedro", "Lopez", 1982);
  stt.add_row(3, "Julio", "Taborga", 1991);
  stt.add_row(4, "Liz", "Suarez", 1992);
  stt.add_row(8, "Omar", "Vera", 1986);

  return db["students"].get_row_count() == 5;
}

bool test3()
{
  memory_db db{"college"};
  auto &stt = db.add_table("students");
  stt.add_columns(column_info{"id", col::integer},
                  column_info{"first_name", col::string},
                  column_info{"last_name", col::string},
                  column_info{"birthyear", col::integer});

  stt.add_row(1, "Juan", "Perez", 1980);
  stt.add_row(2, "Pedro", "Lopez", 1982);
  stt.add_row(3, "Julio", "Taborga", 1991);
  stt.add_row(4, "Liz", "Suarez", 1992);
  stt.add_row(8, "Omar", "Vera", 1986);

  auto &rows = stt.get_all_rows();
  std::string r;
  for (auto &row : rows)
  {
    r += row["id"].as_string() + "," + row["first_name"].as_string() + "," + row["last_name"].as_string() + "," + row["birthyear"].as_string() + ";";
  };

  return r == "1,Juan,Perez,1980;2,Pedro,Lopez,1982;3,Julio,Taborga,1991;4,Liz,Suarez,1992;8,Omar,Vera,1986;";
}

bool test4()
{
  memory_db db{"college"};
  auto &cot = db.add_table("courses");
  cot.add_columns(column_info{"id", col::string},
                  column_info{"name", col::string});

  cot.add_row("mat-101", "Algebra I");
  cot.add_row("mat-203", "Algebra lineal");
  cot.add_row("inf-205", "Taller de programacion I");
  cot.add_row("fis-203", "Fisica I");
  cot.add_row("mat-102", "Introduccion al calculo");
  cot.add_row("fis-204", "Fisica II");
  cot.add_row("mat-204", "Estructuras discretas");
  cot.add_row("inf-206", "Estructuras de datos");
  cot.add_row("mat-305", "Variable compleja");
  cot.add_row("inf-307", "Analisis de algoritmos");

  auto vec = cot.filter_rows([](auto &row) {
    return row["id"].as_string().find("mat-") == 0;
  });

  std::string result;
  for (auto &e : vec)
  {
    result += e["name"].as_string() + "; ";
  }

  return result == "Algebra I; Algebra lineal; Introduccion al calculo; Estructuras discretas; Variable compleja; ";
}

bool test5()
{
  memory_db db{"college"};
  auto &cot = db.add_table("courses");
  cot.add_columns(column_info{"id", col::string},
                  column_info{"name", col::string});

  cot.add_row("mat-101", "Algebra I");
  cot.add_row("mat-203", "Algebra lineal");
  cot.add_row("inf-205", "Taller de programacion I");
  cot.add_row("fis-203", "Fisica I");
  cot.add_row("mat-102", "Introduccion al calculo");
  cot.add_row("fis-204", "Fisica II");
  cot.add_row("mat-204", "Estructuras discretas");
  cot.add_row("inf-206", "Estructuras de datos");
  cot.add_row("mat-305", "Variable compleja");
  cot.add_row("inf-307", "Analisis de algoritmos");

  auto optional_row1 = cot.get_by_id("inf-206");
  auto optional_row2 = cot.get_by_id("fis-222");

  return optional_row1.has_value() && optional_row1.get_row()["name"].as_string() == "Estructuras de datos" && optional_row2.has_value() == false;
}

bool test6()
{
  memory_db db{"system"};
  auto &stt = db.add_table("users");
  stt.add_columns(column_info{"id", col::integer},
                  column_info{"first_name", col::string},
                  column_info{"last_name", col::string},
                  column_info{"email", col::string},
                  column_info{"level", col::integer});

  stt.add_row(1, "Juan", "Perez", "juanpi@hotmail.com", 1);
  stt.add_row(2, "Pedro", "Lopez", "pedrito123@gmail.com", 1);
  stt.add_row(3, "Julio", "Taborga", "taboju322@outlook.com", 2);
  stt.add_row(4, "Liz", "Suarez", "azucena28@yahoo.es", 2);
  stt.add_row(8, "Omar", "Vera", "ovu@rocketmail.com", 1);
  stt.add_row(6, "Mauri", "Salazar", "lobo@lobo.net.bo", 2);

  bool exists = stt.contains_by_id(4);
  stt.delete_by_id(4);
  auto opt = stt.get_by_id(4);

  return exists && !opt.has_value();
}

bool test7()
{
  memory_db db{"system"};
  auto &stt = db.add_table("users");
  stt.add_columns(column_info{"id", col::integer},
                  column_info{"first_name", col::string},
                  column_info{"last_name", col::string},
                  column_info{"email", col::string},
                  column_info{"level", col::integer});

  stt.add_row(1, "Juan", "Perez", "juanpi@hotmail.com", 1);
  stt.add_row(2, "Pedro", "Lopez", "pedrito123@gmail.com", 1);
  stt.add_row(3, "Julio", "Taborga", "taboju322@outlook.com", 2);
  stt.add_row(4, "Liz", "Suarez", "azucena28@yahoo.es", 2);
  stt.add_row(8, "Omar", "Vera", "ovu@rocketmail.com", 1);
  stt.add_row(6, "Mauri", "Salazar", "lobo@lobo.net.bo", 2);

  stt.delete_rows([](auto &r) {
    return r["email"].as_string().find(".com") != std::string::npos;
  });

  auto rows = stt.get_all_rows();
  std::string result;
  for (auto &row : rows)
  {
    result += row["email"].as_string() + ";";
  }

  return result == "azucena28@yahoo.es;lobo@lobo.net.bo;";
}

int main()
{
  size_t score = 0;

  std::vector<bool (*)()> tests{
      test0, test1, test2, test3,
      test4, test5, test6, test7};

  for (auto test : tests)
  {
    score += test();
  }

  std::cout << score << " / " << tests.size() << "\n";

  return 0;
}