# HOW TO BUILD

## Docker (The best solution)

sudo docker build -t task_app . <br>
sudo docker run -it --rm task_app

## Wtihout docker

cmake CMakeLists.txt <br>
make <br>
./tasks_app <br>


## Список комманд:
>>  taskname description 2022-12-23 00:00 category
>>>	каждый параметр вбивается "одним словом". 
>>>	время указывать опционально, но дату - обязательно.

>> update taskname

>>	delete taskname

>>	done taskname

>>	select name, description, date, status where name = "taskname" and date <= 2022-12-23 00:12

>>>	можно использоваться *, чтобы вывести все параметры (name, description, date, status = *)
	
>>>	ключевое слово like для поиска подстроки в строке

