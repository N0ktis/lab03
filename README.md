Журин Алексей ИУ8-22

Tutorial

$ export GITHUB_USERNAME=<имя_пользователя> //создаем переменную с именем пользователя
$ export GITHUB_EMAIL=<адрес_почтового_ящика> //создаём переменую с почтовым адресом пользователя
$ export GITHUB_TOKEN=<сгенирированный_токен> //создаём переменную со значением сгенерированного тоекна
$ alias edit=<nano|vi|vim|subl> //задаём базовый текстовый редактор

$ cd ${GITHUB_USERNAME}/workspace //перемещаемся в указанную директорию
$ source scripts/activate //запускаем скрипт

$ mkdir ~/.config //создаём исполняемый файл в домашней директории
$ cat > ~/.config/hub <<EOF //заполняем файл со стандартного ввода
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https //изменяем настройки гита

$ mkdir projects/lab02 && cd projects/lab02 //создаём новый папку и перемещаемся в неё
$ git init //создаём пустой репозиторий
$ git config --global user.name ${GITHUB_USERNAME} //изменяем настройки гита, задаём имя пользователя
$ git config --global user.email ${GITHUB_EMAIL} //изменям настройки гита, задаёмпочтовый адресс пользователя
$ git config -e --global ||смотрим текущие настройки гита
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git //задаём кдалённому репозиторию имя, чтобы было проще обращаться
$ git pull origin master //выгражаем файлы из удалённого репозитоия в текщущий локальный
$ touch README.md //создаём файл с именем README.md
$ git status //запрашиваем статус репозиторию
$ git add README.md //добавляем созданный файл в репозиторий
$ git commit -m"added README.md" //добавляем коммит
$ git push origin master //выгружаем и обновляем текущий репозиторий на гит

Добавить на сервисе GitHub в репозитории lab02 файл .gitignore со следующем содержимом:

*build*/
*install*/
*.swp
.idea/

$ git pull origin master //выгружаем файлы удалённого репозитория в текущий локальный
$ git log //смотрим все коммиты

$ mkdir sources //создаём папку
$ mkdir include //создаём папку
$ mkdir examples //создаём папку
$ cat > sources/print.cpp <<EOF //создаём и заполняем файл со стандартоного ввода
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF

$ cat > include/print.hpp <<EOF //создаём и заполняем файл со стандартного ввода
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF

$ cat > examples/example1.cpp <<EOF //создаём и запоняем файл со стандартного ввода
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF

$ cat > examples/example2.cpp <<EOF //создаём и запоняем файл со стандартного ввода
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF

$ edit README.md //изменяем файл README.md

$ git status //смотрим информайию о текущем дереве разработки
$ git add . //добавляем в удалённый репозиторий все файлы, что хранятся в локальном 
$ git commit -m"added sources" //делаем коммит
$ git push origin master //выгружаем и обновляем текущий репозиторий на гит

Report

$ cd ~/workspace/labs/ //перемещаемся в текущую директрию
$ export LAB_NUMBER=02 //задаём значение переменной
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER} //загружаем файл с указанного ресурса в указанную директорию
$ mkdir reports/lab${LAB_NUMBER} //создаём папку с именем lab02
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md //переименовываем файл
$ cd reports/lab${LAB_NUMBER} //перемещаемся в уазанную директорию
$ edit REPORT.md //редактируем файл
$ gistu
