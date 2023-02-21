#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Model.hpp"
#include <Wt/Dbo/Exception.h>
#include "DatabaseRoutine.h"

static const std::string connectionString =
"host=localhost"
" port=5432"
" dbname=sales"
" user=postgres"
" password=admin";

enum class Action
{
	FirstAction = 1,
	CreateSchema = 1,
	CreateSampleData = 2,
	GetReport = 3,
	Exit = 4,
	Lastaction = 4
};

void printActions()
{
	std::cout << static_cast<int>(Action::CreateSchema) << ". Создать схему базы данных" << std::endl;
	std::cout << static_cast<int>(Action::CreateSampleData) << ". Создать тестовые данные" << std::endl;
	std::cout << static_cast<int>(Action::GetReport) << ". Вывести отчет" << std::endl;
	std::cout << static_cast<int>(Action::Exit) << ". Выход" << std::endl;
}

Action getUserInput()
{
	int input;
	bool reEnter = false;
	do
	{
		if (reEnter)
		{
			std::cout << "Неверное действие, повторите ввод." << std::endl;
		}

		std::cout << "Ввод:";

		reEnter = true;
		std::cin >> input;
	} while (input < static_cast<int>(Action::FirstAction) || input > static_cast<int>(Action::Lastaction));
	return static_cast<Action>(input);
}

void getReport(Wt::Dbo::Session& session)
{
	std::cout << "Выберите издательство по номеру." << std::endl;
	auto publishers = DatabaseRoutine::getPublishers(session);
	for (int i = 0; i < publishers.size(); ++i)
	{
		std::cout << i + 1 << ". " << publishers[i]->name << std::endl;
	}

	int input;
	bool reEnter = false;
	do
	{
		if (reEnter)
		{
			std::cout << "Неверный номер, повторите ввод." << std::endl;
		}

		std::cout << "Ввод:";

		reEnter = true;
		std::cin >> input;
	} while (input < 1 || input > publishers.size());

	auto publisherId = publishers[input].id();
	auto shops = DatabaseRoutine::getShops(session, publisherId);
	std::cout << "Магазины, продающие книги выбранного издательства:" << std::endl;
	for (int i = 0; i < shops.size(); ++i)
	{
		std::cout << i + 1 << ". " << shops[i]->name << std::endl;
	}

	std::cout << std::endl;
}

void performDbAction(Action action)
{
	try
	{

		auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
		Wt::Dbo::Session session;
		session.setConnection(std::move(postgres));
		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Stock>("stock");
		session.mapClass<Shop>("shop");
		session.mapClass<Sale>("sale");


		switch (action)
		{
		case Action::CreateSchema:
			DatabaseRoutine::createSchema(session);
			break;
		case Action::CreateSampleData:
			DatabaseRoutine::createSampleData(session);
			break;
		case Action::GetReport:
			getReport(session);
			break;
		}
	}
	catch (Wt::Dbo::Exception& e)
	{
		std::cout << "Ошибка при работе с БД: " << e.what() << std::endl;
	}
}



int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");


	do
	{
		std::cout << "Выберите действие." << std::endl;
		printActions();
		auto action = getUserInput();

		if (action == Action::Exit)
		{
			break;
		}
		else
		{
			performDbAction(action);
		}

	} while (true);
}

