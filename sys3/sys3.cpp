
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

//class User {
//public:
//    string name;
//    int id;
//    User(string n, int i) : name(n), id(i) {}
//};
//
//class Book {
//public:
//    string title;
//    string author;
//    int id;
//    bool available;
//    Book(string t, string a, int i) : title(t), author(a), id(i), available(true) {}
//};
//
//class Loan {
//public:
//    int userId;
//    int bookId;
//    time_t dueDate;
//    Loan(int u, int b, time_t d) : userId(u), bookId(b), dueDate(d) {}
//};
//
//class Reservation {
//public:
//    int userId;
//    int bookId;
//    Reservation(int u, int b) : userId(u), bookId(b) {}
//};
//
//class Fine {
//public:
//    int userId;
//    double amount;
//    Fine(int u, double a) : userId(u), amount(a) {}
//};
//
//class Library {
//private:
//    vector<User> users;
//    vector<Book> books;
//    vector<Loan> loans;
//    vector<Reservation> reservations;
//    vector<Fine> fines;
//public:
//    void addUser(string name, int id) {
//        users.emplace_back(name, id);
//    }
//
//    void addBook(string title, string author, int id) {
//        books.emplace_back(title, author, id);
//    }
//
//    void borrowBook(int userId, int bookId) {
//        auto book = find_if(books.begin(), books.end(), [bookId](Book& b) { return b.id == bookId; });
//        if (book != books.end() && book->available) {
//            time_t now = time(0);
//            loans.emplace_back(userId, bookId, now + 14 * 24 * 60 * 60); 
//            book->available = false;
//            cout << "Книга выдана" << endl;
//        }
//        else {
//            cout << "Книга недоступна" << endl;
//        }
//    }
//
//    void returnBook(int userId, int bookId) {
//        auto loan = find_if(loans.begin(), loans.end(), [userId, bookId](Loan& l) { return l.userId == userId && l.bookId == bookId; });
//        if (loan != loans.end()) {
//            time_t now = time(0);
//            if (now > loan->dueDate) {
//                double fineAmount = (now - loan->dueDate) / (24 * 60 * 60) * 10; 
//                fines.emplace_back(userId, fineAmount);
//                cout << "Начислен штраф: " << fineAmount << " руб." << endl;
//            }
//            auto book = find_if(books.begin(), books.end(), [bookId](Book& b) { return b.id == bookId; });
//            if (book != books.end()) {
//                book->available = true;
//            }
//            loans.erase(loan);
//            cout << "Книга возвращена" << endl;
//        }
//    }
//
//    void reserveBook(int userId, int bookId) {
//        reservations.emplace_back(userId, bookId);
//        cout << "Книга зарезервирована" << endl;
//    }
//
//    void searchBook(string title) {
//        for (auto& book : books) {
//            if (book.title.find(title) != string::npos) {
//                cout << "Найдена книга: " << book.title << " (" << book.author << ")" << endl;
//            }
//        }
//    }
//};
//
//
//class TeamMember {
//public:
//    string name;
//    TeamMember(string n) : name(n) {}
//};
//
//class Task {
//public:
//    string description;
//    int storyPoints;
//    bool completed;
//    Task(string d, int sp) : description(d), storyPoints(sp), completed(false) {}
//};
//
//class UserStory {
//public:
//    string title;
//    vector<Task> tasks;
//    UserStory(string t) : title(t) {}
//    void addTask(string desc, int sp) {
//        tasks.emplace_back(desc, sp);
//    }
//};
//
//class Backlog {
//public:
//    vector<UserStory> stories;
//    void addStory(UserStory story) {
//        stories.push_back(story);
//    }
//};
//
//class Sprint {
//public:
//    vector<UserStory> stories;
//    vector<TeamMember> members;
//    void addStory(UserStory story) {
//        stories.push_back(story);
//    }
//    void addMember(TeamMember member) {
//        members.push_back(member);
//    }
//};
//
//class BurndownChart {
//public:
//    void showChart() {
//        cout << "График сгорания задач" << endl;
//    }
//};
//
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//
//    Library lib;
//    lib.addUser("Иван", 1);
//    lib.addBook("Война и мир", "Толстой", 101);
//    lib.borrowBook(1, 101);
//    lib.returnBook(1, 101);
//    lib.reserveBook(1, 101);
//    lib.searchBook("Война");
//
//
//    Backlog backlog;
//    UserStory story("Регистрация пользователя");
//    story.addTask("Создать форму", 3);
//    backlog.addStory(story);
//
//    Sprint sprint;
//    sprint.addStory(story);
//    sprint.addMember(TeamMember("Петр"));
//
//    BurndownChart chart;
//    chart.showChart();

//}




class TeamMember {
public:
    string name;
    TeamMember(string n) : name(n) {}
};

class Task {
public:
    string description;
    bool completed;
    Task(string d) : description(d), completed(false) {}
    void markCompleted() {
        completed = true;
        cout << "Задача '" << description << "' выполнена" << endl;
    }
};

class UserStory {
public:
    string title;
    vector<Task> tasks;
    UserStory(string t) : title(t) {}
    void addTask(string desc) {
        tasks.emplace_back(desc);
        cout << "Добавлена задача: " << desc << endl;
    }
};

class Backlog {
public:
    vector<UserStory> stories;
    void addStory(UserStory story) {
        stories.push_back(story);
        cout << "Добавлена история: " << story.title << endl;
    }
};

class Sprint {
public:
    string name;
    vector<UserStory> stories;
    vector<TeamMember> members;
    Sprint(string n) : name(n) {}
    void addStory(UserStory story) {
        stories.push_back(story);
        cout << "История добавлена в спринт: " << story.title << endl;
    }
    void addMember(TeamMember member) {
        members.push_back(member);
        cout << "Участник добавлен в спринт: " << member.name << endl;
    }
};



class Patient {
public:
    string name;
    int id;
    Patient(string n, int i) : name(n), id(i) {}
};

class Doctor {
public:
    string name;
    string specialty;
    Doctor(string n, string s) : name(n), specialty(s) {}
};

class Appointment {
public:
    int patientId;
    int doctorId;
    string date;
    Appointment(int p, int d, string dt) : patientId(p), doctorId(d), date(dt) {}
};

class MedicalRecord {
public:
    int patientId;
    string diagnosis;
    MedicalRecord(int p, string d) : patientId(p), diagnosis(d) {}
};

class Prescription {
public:
    int patientId;
    string medication;
    Prescription(int p, string m) : patientId(p), medication(m) {}
};

class Billing {
public:
    int patientId;
    double amount;
    Billing(int p, double a) : patientId(p), amount(a) {}
};

class HospitalSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
public:
    void addPatient(string name, int id) {
        patients.emplace_back(name, id);
        cout << "Пациент добавлен: " << name << endl;
    }

    void addDoctor(string name, string specialty) {
        doctors.emplace_back(name, specialty);
        cout << "Доктор добавлен: " << name << " (" << specialty << ")" << endl;
    }

    void createAppointment(int patientId, int doctorId, string date) {
        appointments.emplace_back(patientId, doctorId, date);
        cout << "Запись на прием создана на " << date << endl;
    }

    void findDoctor(string specialty) {
        cout << "Доктора по специальности " << specialty << ":" << endl;
        for (auto& d : doctors) {
            if (d.specialty == specialty) {
                cout << "- " << d.name << endl;
            }
        }
    }
};





class ExternalAPI {
public:
    string name;
    ExternalAPI(string n) : name(n) {}
    void connect() {
        cout << "Подключено к API: " << name << endl;
    }
    void getTaskTime() {
        cout << "Получено время выполнения задач из API" << endl;
    }
};

class Notification {
public:
    void send(string message) {
        cout << "Отправлено уведомление: " << message << endl;
    }
};

class Report {
public:
    void generate() {
        cout << "Сгенерирован отчет по проекту" << endl;
    }
};

class User {
public:
    string name;
    User(string n) : name(n) {}
};

class Task1 {
public:
    string title;
    bool completed;
    Task1(string t) : title(t), completed(false) {}
    void complete() {
        completed = true;
        cout << "Задача '" << title << "' выполнена" << endl;
    }
};

class Project {
public:
    string name;
    vector<Task1> tasks;
    ExternalAPI api;
    Project(string n, ExternalAPI a) : name(n), api(a) {}
    void addTask(string title) {
        tasks.emplace_back(title);
        cout << "Добавлена задача: " << title << endl;
    }
    void syncWithAPI() {
        api.connect();
        api.getTaskTime();
    }
};


class Venue {
public:
    string name;
    int capacity;
    Venue(string n, int c) : name(n), capacity(c) {}
};

class Participant {
public:
    string name;
    Participant(string n) : name(n) {}
};

class Ticket {
public:
    int eventId;
    int participantId;
    Ticket(int e, int p) : eventId(e), participantId(p) {}
};

class Feedback {
public:
    int eventId;
    string comment;
    Feedback(int e, string c) : eventId(e), comment(c) {}
};

class Schedule {
public:
    map<string, string> events;
    void addEvent(string date, string name) {
        events[date] = name;
        cout << "Событие добавлено в расписание: " << date << " - " << name << endl;
    }
};

class Event {
public:
    string name;
    Venue venue;
    vector<Participant> participants;
    Event(string n, Venue v) : name(n), venue(v) {}
    void registerParticipant(string name) {
        participants.emplace_back(name);
        cout << "Участник зарегистрирован: " << name << endl;
    }
};


class Currency {
public:
    string code;
    double rate;
    Currency(string c, double r) : code(c), rate(r) {}
};

class ExchangeRate {
public:
    map<string, double> rates;
    void updateRate(string currency, double rate) {
        rates[currency] = rate;
        cout << "Курс обновлен: " << currency << " = " << rate << endl;
    }
};

class Account {
public:
    string name;
    double balance;
    Account(string n, double b) : name(n), balance(b) {}
};

class Transaction {
public:
    int fromAccount;
    int toAccount;
    double amount;
    Transaction(int f, int t, double a) : fromAccount(f), toAccount(t), amount(a) {}
};

class Budget {
public:
    map<string, double> categories;
    void addCategory(string name, double amount) {
        categories[name] = amount;
        cout << "Добавлена категория бюджета: " << name << " - " << amount << endl;
    }
};


class Database {
public:
    void connect() {
        cout << "Подключение к базе данных установлено" << endl;
    }
};

class MessageQueue {
public:
    void send(string message) {
        cout << "Сообщение отправлено в очередь: " << message << endl;
    }
};

class LoadBalancer {
public:
    void balance() {
        cout << "Нагрузка распределена между сервисами" << endl;
    }
};

class Service {
public:
    string name;
    Service(string n) : name(n) {}
    void start() {
        cout << "Сервис запущен: " << name << endl;
    }
};

class API {
public:
    void handleRequest() {
        cout << "Запрос обработан API" << endl;
    }
};
int main() {
    setlocale(LC_ALL, "ru");

    Backlog backlog;
    UserStory story1("Регистрация пользователя");
    story1.addTask("Создать форму ввода");
    story1.addTask("Реализовать валидацию");
    backlog.addStory(story1);

    Sprint sprint("Спринт 1");
    sprint.addStory(story1);
    sprint.addMember(TeamMember("Иван Петров"));

   
 

    HospitalSystem hospital;
    hospital.addPatient("Алексей Иванов", 1);
    hospital.addDoctor("Сергей Смирнов", "Кардиолог");
    hospital.addDoctor("Ольга Васильева", "Терапевт");

    hospital.createAppointment(1, 1, "2025-12-15 10:00");
    hospital.findDoctor("Терапевт");


    ExternalAPI jiraAPI("Jira");
    Project project("Веб-сайт", jiraAPI);
    project.addTask("Дизайн главной страницы");
    project.syncWithAPI();

    Notification notification;
    notification.send("Проект 'Веб-сайт' обновлен");

   

    Venue concertHall("Концертный зал", 500);
    Event concert("Рок-фестиваль", concertHall);
    concert.registerParticipant("Иван Иванов");

    Schedule schedule;
    schedule.addEvent("2023-12-20", "Рок-фестиваль");

   
   
    ExchangeRate rates;
    rates.updateRate("USD", 90.5);

    Budget companyBudget;
    companyBudget.addCategory("Маркетинг", 500000);

 
    Service authService("Аутентификация");
    authService.start();

    MessageQueue queue;
    queue.send("Обновление данных пользователя");
}