# HOW TO BUILD

## Docker (The best solution)

sudo docker build -t task_app . <br>
sudo docker run -it --rm task_app

## Wtihout docker

cmake CMakeLists.txt <br>
make <br>
./tasks_app <br>


## Список комманд:
>>  пример: taskname description 2022-12-23 00:00 category_name
>>>	каждый параметр вбивается "одним словом" в двойных кавычках. 
>>>	время указывать опционально, но дату - обязательно.

>> update taskname

>>	delete taskname

>>	done taskname

>>	select name, description, date, status where name = "taskname" and date <= "2022-12-23 00:12" and status = "undone"

>>>	можно использоваться *, чтобы вывести все параметры (name, description, date, status = *)
	
>>>	ключевое слово like для поиска подстроки в строке

>> exit чтобы выйти из программы