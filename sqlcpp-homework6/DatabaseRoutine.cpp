#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Model.hpp"

namespace DatabaseRoutine
{
	void createSchema(Wt::Dbo::Session& session)
	{
		session.createTables();
	}

	void createRandomStocksAndSales(Wt::Dbo::Session& session, std::vector<Wt::Dbo::ptr<Shop>>& shopList, Wt::Dbo::ptr<Book>& bookPtr)
	{
		auto stockCount = rand() % shopList.size();
		for (auto i = 0; i < stockCount; i++)
		{
			auto shopNumber = rand() % shopList.size();
			auto shopPtr = shopList[shopNumber];
			std::unique_ptr<Stock> stock{ new Stock() };
			stock->count = rand() % 100;
			auto stockPtr = session.add(std::move(stock));
			stockPtr.modify()->book = bookPtr;
			stockPtr.modify()->shop = shopPtr;

			auto salesCount = rand() % 5;
			for (auto i = 0; i < salesCount; i++)
			{
				auto price = static_cast<double>(rand() % 2000);
				Wt::WDate date(2022, rand() % 12 + 1, rand() % 30 + 1);
				std::unique_ptr<Sale> sale{ new Sale() };
				sale->count = rand() % 2;
				sale->dateSale = date;
				sale->price = price;
				auto salePtr = session.add(std::move(sale));
				salePtr.modify()->stock = stockPtr;
			}
		}
	}

	void createSampleData(Wt::Dbo::Session& session)
	{
		// Код этого метода сгенерирован на основе списка книг

		Wt::Dbo::Transaction transaction{ session };

		std::vector<Wt::Dbo::ptr<Shop>> shopList;

		// Создаем магазины

		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "100000 книг";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Библио-Глобус";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Библион";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Ботаник";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Букбастер";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Букбери";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Буквоед";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Букервиль";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книгазин";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книги и книжечки";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книговоз";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книгоград";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книжная нора";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книжная полка";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книжный Барс";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Книжный бульвар";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Лас-Книгас";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Новый книжный";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "От А до Я";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Переплётные птицы";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Почитайка";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Пушкинист";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Свой Книжный";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Узнай-ка!";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Читай-город";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Читайка";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Читайна";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}
		{
			std::unique_ptr<Shop> shop{ new Shop() };
			shop->name = "Читалка";
			auto shopPtr = session.add(std::move(shop));
			shopList.push_back(shopPtr);
		}



		// Создаем издателей, их книги и стоки
		{
			std::string name("Интернет-университет информационных технологий");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Архитектура и технологии IBM eServer zSeries / В.А. Варфоломеев и др.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Юрайт");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Владимир, Михайлович Илюшечкин Основы использования и проектирования баз данных / Владимир Михайлович Илюшечкин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Форум");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Голицына, О. Л. Базы данных / О.Л. Голицына, Н.В. Максимов, И.И. Попов.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Москва: РГГУ");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Зубов, А. В. Основы искусственного интеллекта для лингвистов / А.В. Зубов, И.И. Зубова.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Юрайт");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Илюшечкин, В. М. Основы использования и проектирования баз данных / В.М. Илюшечкин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Юрайт");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Илюшечкин, В. М. Основы использования и проектирования баз данных. Учебник / В.М. Илюшечкин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Омега-Л");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Исаев, Г. Н. Информационные системы в экономике. Учебник / Г.Н. Исаев.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Питер");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Карпова, И. П. Базы данных / И.П. Карпова.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("БХВ-Петербург");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Кириллов, В.В. Введение в реляционные базы данных (+ CD-ROM) / В.В. Кириллов.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("ФИЗМАТЛИТ");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Комплекснозначные и гиперкомплексные системы в задачах обработки многомерных сигналов / Я.А. Фурман и др.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Высшая школа");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Костин, А. Е. Организация и обработка структур данных в вычислительных системах. Учебное пособие / А.Е. Костин, В.Ф. Шаньгин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Москва: ИЛ");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Кудрявцев, В.Б. Интеллектуальные системы. Учебник и практикум для бакалавриата и магистратуры / В.Б. Кудрявцев, Э.Э. Гасанов, А.С. Подколзин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Бином-Пресс, 2013.");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Кузнецов, С. Д. Базы данных. Модели и языки / С.Д. Кузнецов.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Бином. Лаборатория знаний, Интернет-университет информационных технологий");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Кузнецов, С. Д. Основы баз данных / С.Д. Кузнецов.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Москва: Высшая школа, 2016.");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Латыпова, Р. Р. Базы данных. Курс лекций / Р.Р. Латыпова.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Форум");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Мартишин, С. А. Базы данных. Практическое примечание СУБД SQL и NoSOL. Учебное пособие / С.А. Мартишин, В.Л. Симонов, М.В. Храпченко.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Юрайт");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Миркин, Б. Г. Введение в анализ данных. Учебник и практикум / Б.Г. Миркин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Радиотехника");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Нейрокомпьютеры в системах обработки изображений.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Академия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Остроух, А. В. Ввод и обработка цифровой информации / А.В. Остроух.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Москва: Огни");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Персианов, Вячеслав Венедиктович; Технология Проектирования Информационной Базы Для Педагогических Вузов Страны. / Персианов Вячеслав Венедиктович;.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Москва: Гостехиздат");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Персианов, Вячеслав Венедиктович; Электронное Образовательное Пространство Педагогического Университета:Формирование, Применение, Проблемы / Персианов Вячеслав Венедиктович;.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Горячая линия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Проектирование баз данных. СУБД Microsoft Access. Учебное пособие.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Академия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Свиридова, М. Ю. Система управления базами данных Access / М.Ю. Свиридова.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Высшая школа");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Советов, Б. Я. Моделирование систем / Б.Я. Советов, С.А. Яковлев.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Юрайт");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Стружкин, Н. П. Базы данных. Проектирование. Учебник / Н.П. Стружкин, В.В. Годин.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Академия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Фуфаев, Э. В. Базы данных / Э.В. Фуфаев, Д.Э. Фуфаев.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Академия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Фуфаев, Э. В. Базы данных. Учебное пособие / Э.В. Фуфаев, Д.Э. Фуфаев.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Книга по Требованию");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Хомоненко, А. Работа с базами данных в C++ BUILDER / А. Хомоненко.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		{
			std::string name("Горячая линия");
			Wt::Dbo::ptr<Publisher> publisherPtr = session.find<Publisher>().where("name = ?").bind(name);
			if (!publisherPtr)
			{
				std::unique_ptr<Publisher> publisher{ new Publisher() };
				publisher->name = name;
				publisherPtr = session.add(std::move(publisher));
			}

			std::unique_ptr<Book> book{ new Book() };
			book->title = "Цуканова, Н. И. Онтологическая модель представления и организации знаний. Учебное пособие / Н.И. Цуканова.";
			auto bookPtr = session.add(std::move(book));
			bookPtr.modify()->publisher = publisherPtr;

			createRandomStocksAndSales(session, shopList, bookPtr);

		}

		transaction.commit();
	}

	std::vector<Wt::Dbo::ptr<Publisher>> getPublishers(Wt::Dbo::Session& session)
	{
		Wt::Dbo::Transaction transaction{ session };
		std::vector<Wt::Dbo::ptr<Publisher>> res;
		Wt::Dbo::collection<Wt::Dbo::ptr<Publisher>> publishers = session.find<Publisher>();
		for (const Wt::Dbo::ptr<Publisher>& item : publishers)
		{
			res.push_back(item);
		}

		return res;
	}

	std::vector<Wt::Dbo::ptr<Shop>> getShops(Wt::Dbo::Session& session, Wt::Dbo::dbo_default_traits::IdType publisherId)
	{
		Wt::Dbo::Transaction transaction{ session };
		std::vector<Wt::Dbo::ptr<Shop>> res;
		std::string query = "SELECT DISTINCT s\
			FROM\
			shop s\
			JOIN stock st ON st.shop_id = s.id\
			JOIN book b ON st.book_id = b.id\
			JOIN publisher p ON b.publisher_id = p.id\
			WHERE p.id = ?";

		Wt::Dbo::collection<Wt::Dbo::ptr<Shop>> shops = session.query<Wt::Dbo::ptr<Shop>>(query).bind(publisherId);
		for (const Wt::Dbo::ptr<Shop>& item : shops)
		{
			res.push_back(item);
		}

		return res;
	}
}