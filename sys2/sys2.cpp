#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;


class Permission {
private:
    string name;
    string description;

public:
    Permission(const string& name, const string& description)
        : name(name), description(description) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
};


class Role {
private:
    string name;
    vector<Permission> permissions;

public:
    Role(const string& name) : name(name) {}

    void addPermission(const Permission& permission) {
        permissions.push_back(permission);
    }

    bool hasPermission(const string& permissionName) const {
        for (const auto& perm : permissions) {
            if (perm.getName() == permissionName) {
                return true;
            }
        }
        return false;
    }

    string getName() const { return name; }
};


class Comment {
private:
    string author;
    string content;
    time_t timestamp;

public:
    Comment(const string& author, const string& content)
        : author(author), content(content) {
        timestamp = time(nullptr);
    }

    string getAuthor() const { return author; }
    string getContent() const { return content; }
 
    
};


class Task {
private:
    string id;
    string title;
    string description;
    string status;
    string assignee;
    vector<Comment> comments;

public:
    Task(const string& id, const string& title, const string& description)
        : id(id), title(title), description(description), status("Новая") {}

    void setAssignee(const string& user) { assignee = user; }
    void setStatus(const string& newStatus) { status = newStatus; }

    void addComment(const Comment& comment) {
        comments.push_back(comment);
    }

    string getId() const { return id; }
    string getTitle() const { return title; }
    string getStatus() const { return status; }
    string getAssignee() const { return assignee; }
    vector<Comment> getComments() const { return comments; }
};


class Project {
private:
    string id;
    string name;
    string description;
    vector<Task> tasks;
    vector<string> teamMembers;
    vector<Comment> comments;

public:
    Project(const string& id, const string& name, const string& description)
        : id(id), name(name), description(description) {}

    void addTeamMember(const string& userId) {
        teamMembers.push_back(userId);
    }

    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void addComment(const Comment& comment) {
        comments.push_back(comment);
    }

    string getId() const { return id; }
    string getName() const { return name; }
    vector<Task> getTasks() const { return tasks; }
    vector<string> getTeamMembers() const { return teamMembers; }
    vector<Comment> getComments() const { return comments; }
};


class User {
private:
    string id;
    string username;
    string email;
    Role role;
    vector<string> notifications;

public:
    User(const string& id, const string& username, const string& email, const Role& role)
        : id(id), username(username), email(email), role(role) {}

    bool hasPermission(const string& permissionName) const {
        return role.hasPermission(permissionName);
    }

    void addNotification(const string& message) {
        notifications.push_back(message);
    }

    string getId() const { return id; }
    string getUsername() const { return username; }
    string getEmail() const { return email; }
    Role getRole() const { return role; }
    vector<string> getNotifications() const { return notifications; }
};
class Student {
private:
    string id;
    string name;
    string email;

public:
    Student(const string& id, const string& name, const string& email)
        : id(id), name(name), email(email) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
};


class Instructor {
private:
    string id;
    string name;
    string email;
    string department;

public:
    Instructor(const string& id, const string& name, const string& email, const string& department)
        : id(id), name(name), email(email), department(department) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getDepartment() const { return department; }
};


class Course {
private:
    string id;
    string title;
    string description;
    Instructor instructor;
    int credits;

public:
    Course(const string& id, const string& title, const string& description,
        const Instructor& instructor, int credits)
        : id(id), title(title), description(description),
        instructor(instructor), credits(credits) {}

    string getId() const { return id; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    Instructor getInstructor() const { return instructor; }
    int getCredits() const { return credits; }
};


class Grade {
private:
    string studentId;
    string courseId;
    char grade;

public:
    Grade(const string& studentId, const string& courseId, char grade)
        : studentId(studentId), courseId(courseId), grade(grade) {}

    string getStudentId() const { return studentId; }
    string getCourseId() const { return courseId; }
    char getGrade() const { return grade; }
};


class Schedule {
private:
    string courseId;
    string dayOfWeek;
    string time;
    string classroom;

public:
    Schedule(const string& courseId, const string& dayOfWeek,
        const string& time, const string& classroom)
        : courseId(courseId), dayOfWeek(dayOfWeek),
        time(time), classroom(classroom) {}

    string getCourseId() const { return courseId; }
    string getDayOfWeek() const { return dayOfWeek; }
    string getTime() const { return time; }
    string getClassroom() const { return classroom; }
};


class Enrollment {
private:
    string studentId;
    string courseId;
    string enrollmentDate;

public:
    Enrollment(const string& studentId, const string& courseId, const string& enrollmentDate)
        : studentId(studentId), courseId(courseId), enrollmentDate(enrollmentDate) {}

    string getStudentId() const { return studentId; }
    string getCourseId() const { return courseId; }
    string getEnrollmentDate() const { return enrollmentDate; }
};


class ReportGenerator {
public:
    static void generateStudentReport(const Student& student,
        const vector<Enrollment>& enrollments,
        const vector<Grade>& grades,
        const vector<Course>& courses) {
        cout << "Отчет по успеваемости студента: " << student.getName() << endl;
      

        for (const auto& enrollment : enrollments) {
            if (enrollment.getStudentId() == student.getId()) {
          
                auto courseIt = find_if(courses.begin(), courses.end(),
                    [&enrollment](const Course& c) { return c.getId() == enrollment.getCourseId(); });

                if (courseIt != courses.end()) {
                    cout << "Курс: " << courseIt->getTitle()  << endl;

                    
                    auto gradeIt = find_if(grades.begin(), grades.end(),
                        [&student, &enrollment](const Grade& g) {
                            return g.getStudentId() == student.getId() &&
                                g.getCourseId() == enrollment.getCourseId();
                        });

                    if (gradeIt != grades.end()) {
                        cout << "Оценка: " << gradeIt->getGrade() << endl;
                    }
                    else {
                        cout << "Оценка: не выставлена" << endl;
                    }
                   
                }
            }
        }
    }
};

class Product {
private:
    string id;
    string name;
    double price;
    int stock;

public:
    Product(string id, string name, double price, int stock)
        : id(id), name(name), price(price), stock(stock) {}

    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    void reduceStock(int quantity) {
        stock -= quantity;
    }
};

class Customer {
private:
    string id;
    string name;
    string address;
    vector<string> orderHistory;

public:
    Customer(string id, string name, string address)
        : id(id), name(name), address(address) {}

    void addOrder(string orderId) {
        orderHistory.push_back(orderId);
    }

    string getId() const { return id; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    vector<string> getOrderHistory() const { return orderHistory; }
};


class ShoppingCart {
private:
    string customerId;
    map<string, int> items; 

public:
    ShoppingCart(string customerId) : customerId(customerId) {}

    void addItem(string productId, int quantity) {
        items[productId] += quantity;
    }

    void removeItem(string productId) {
        items.erase(productId);
    }

    map<string, int> getItems() const { return items; }
    string getCustomerId() const { return customerId; }
};


class Payment {
private:
    string id;
    string orderId;
    double amount;
    string status;

public:
    Payment(string id, string orderId, double amount)
        : id(id), orderId(orderId), amount(amount), status("Ожидает оплаты") {}

    void processPayment() {
        status = "Оплачено";
    }

    string getId() const { return id; }
    string getOrderId() const { return orderId; }
    double getAmount() const { return amount; }
    string getStatus() const { return status; }
};


class Shipping {
private:
    string id;
    string orderId;
    string address;
    string status;

public:
    Shipping(string id, string orderId, string address)
        : id(id), orderId(orderId), address(address), status("Ожидает отправки") {}

    void shipOrder() {
        status = "Отправлено";
    }

    void deliverOrder() {
        status = "Доставлено";
    }

    string getId() const { return id; }
    string getOrderId() const { return orderId; }
    string getAddress() const { return address; }
    string getStatus() const { return status; }
};


class Order {
private:
    string id;
    string customerId;
    vector<pair<string, int>> items; 
    string status;
    string paymentId;
    string shippingId;

public:
    Order(string id, string customerId, const vector<pair<string, int>>& items)
        : id(id), customerId(customerId), items(items), status("Создан") {}

    void setPayment(string paymentId) {
        this->paymentId = paymentId;
        status = "Оплата обрабатывается";
    }

    void setShipping(string shippingId) {
        this->shippingId = shippingId;
        status = "Ожидает отправки";
    }

    void completeOrder() {
        status = "Завершен";
    }

    string getId() const { return id; }
    string getCustomerId() const { return customerId; }
    vector<pair<string, int>> getItems() const { return items; }
    string getStatus() const { return status; }
    string getPaymentId() const { return paymentId; }
    string getShippingId() const { return shippingId; }
};

class Book {
private:
    string id;
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(string id, string title, string author, string isbn)
        : id(id), title(title), author(author), isbn(isbn), available(true) {}

    void setAvailable(bool status) {
        available = status;
    }

    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbn() const { return isbn; }
    bool isAvailable() const { return available; }
};


class User1 {
private:
    string id;
    string name;
    string contact;

public:
    User1(string id, string name, string contact)
        : id(id), name(name), contact(contact) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getContact() const { return contact; }
};

class Loan {
private:
    string id;
    string bookId;
    string userId;
    string status;

public:
    Loan(string id, string bookId, string userId)
        : id(id), bookId(bookId), userId(userId), status("Активна") {}

    void returnBook() {
        status = "Возвращена";
    }

    void setOverdue() {
        status = "Просрочена";
    }

    string getId() const { return id; }
    string getBookId() const { return bookId; }
    string getUserId() const { return userId; }
    string getStatus() const { return status; }
};


class Reservation {
private:
    string id;
    string bookId;
    string userId;
    string status;

public:
    Reservation(string id, string bookId, string userId)
        : id(id), bookId(bookId), userId(userId), status("Активна") {}

    void cancel() {
        status = "Отменена";
    }

    void fulfill() {
        status = "Выполнена";
    }

    string getId() const { return id; }
    string getBookId() const { return bookId; }
    string getUserId() const { return userId; }
    string getStatus() const { return status; }
};


class Fine {
private:
    string id;
    string userId;
    string loanId;
    double amount;
    string status;

public:
    Fine(string id, string userId, string loanId, double amount)
        : id(id), userId(userId), loanId(loanId), amount(amount), status("Не оплачен") {}

    void pay() {
        status = "Оплачен";
    }

    string getId() const { return id; }
    string getUserId() const { return userId; }
    string getLoanId() const { return loanId; }
    double getAmount() const { return amount; }
    string getStatus() const { return status; }
};


class Library {
private:
    vector<Book> books;
    vector<User1> users;
    vector<Loan> loans;
    vector<Reservation> reservations;
    vector<Fine> fines;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addUser(const User1& user) {
        users.push_back(user);
    }

    Book* findBook(string bookId) {
        for (auto& book : books) {
            if (book.getId() == bookId) {
                return &book;
            }
        }
        return nullptr;
    }

    User1* findUser(string userId) {
        for (auto& user : users) {
            if (user.getId() == userId) {
                return &user;
            }
        }
        return nullptr;
    }

    Loan* findActiveLoan(string bookId) {
        for (auto& loan : loans) {
            if (loan.getBookId() == bookId && loan.getStatus() == "Активна") {
                return &loan;
            }
        }
        return nullptr;
    }

    bool borrowBook(string bookId, string userId) {
        Book* book = findBook(bookId);
        User1* user = findUser(userId);

        if (book && user && book->isAvailable()) {
            book->setAvailable(false);
            loans.emplace_back("loan" + to_string(loans.size() + 1), bookId, userId);
            return true;
        }
        return false;
    }

    bool returnBook(string bookId) {
        Book* book = findBook(bookId);
        Loan* loan = findActiveLoan(bookId);

        if (book && loan) {
            book->setAvailable(true);
            loan->returnBook();
            return true;
        }
        return false;
    }

    bool reserveBook(string bookId, string userId) {
        Book* book = findBook(bookId);
        User1* user = findUser(userId);

        if (book && user && !book->isAvailable()) {
            reservations.emplace_back("res" + to_string(reservations.size() + 1), bookId, userId);
            return true;
        }
        return false;
    }

    vector<Book> searchBooks(string query) {
        vector<Book> result;
        for (const auto& book : books) {
            if (book.getTitle().find(query) != string::npos ||
                book.getAuthor().find(query) != string::npos ||
                book.getIsbn().find(query) != string::npos) {
                result.push_back(book);
            }
        }
        return result;
    }
};


int main() {
    setlocale(LC_ALL, "RU");
   
    Permission createProject("create_project", "Создание новых проектов");
    Permission editProject("edit_project", "Редактирование проектов");
    Permission createTask("create_task", "Создание задач");
    Permission assignTask("assign_task", "Назначение задач");

  
    Role admin("Администратор");
    admin.addPermission(createProject);
    admin.addPermission(editProject);
    admin.addPermission(createTask);
    admin.addPermission(assignTask);

    Role manager("Менеджер");
    manager.addPermission(createTask);
    manager.addPermission(assignTask);

    Role developer("Разработчик");

   
    User user1("1", "Иван Петров", "ivan@example.com", admin);
    User user2("2", "Мария Сидорова", "maria@example.com", manager);
    User user3("3", "Алексей Иванов", "alex@example.com", developer);

   
    Project project("p1", "Новый веб-сайт", "Разработка корпоративного сайта");
    project.addTeamMember(user1.getId());
    project.addTeamMember(user2.getId());
    project.addTeamMember(user3.getId());

    Task task1("t1", "Дизайн главной страницы", "Создать макет главной страницы");
    task1.setAssignee(user3.getId());
    task1.setStatus("В работе");

    Task task2("t2", "Реализация API", "Разработать backend API");
    task2.setStatus("Новая");

    project.addTask(task1);
    project.addTask(task2);

  
    Comment comment1(user2.getUsername(), "Нужно добавить логотип компании в дизайн");
    task1.addComment(comment1);
    user3.addNotification("Новый комментарий к задаче 'Дизайн главной страницы'");

    Comment projectComment(user1.getUsername(), "Проект утвержден, начинаем работу");
    project.addComment(projectComment);

    
    cout << "Проект: " << project.getName() << endl;
    cout << "Участники проекта:" << endl;
    for (const auto& memberId : project.getTeamMembers()) {
        
        cout << "- " << memberId << endl;
    }

    cout << "\nЗадачи проекта:" << endl;
    for (const auto& task : project.getTasks()) {
        cout << "[" << task.getId() << "] " << task.getTitle()
            << " (" << task.getStatus() << ")" << endl;
        if (!task.getAssignee().empty()) {
            cout << "  Назначена: " << task.getAssignee() << endl;
        }
        if (!task.getComments().empty()) {
            cout << "  Комментарии:" << endl;
            for (const auto& comment : task.getComments()) {
                cout << "  - " << comment.getAuthor() << comment.getContent() << endl;
            }
        }
    }


    Instructor instructor1("i1", "Профессор Смирнов", "test@mail.ru", "Информатика");
    Instructor instructor2("i2", "Доцент Иванова", "test@mail.ru", "Математика");

    Student student1("s1", "Александр Козлов", "test@mail.ru");
    Student student2("s2", "Елена Новикова", "test@mail.ru");

    Course course1("c1", "Программирование на C++", "Базовый курс программирования", instructor1, 4);
    Course course2("c2", "Дискретная математика", "Основы дискретной математики", instructor2, 3);

 
    Enrollment enrollment1(student1.getId(), course1.getId(), "2025-09-01");
    Enrollment enrollment2(student1.getId(), course2.getId(), "2025-09-01");
    Enrollment enrollment3(student2.getId(), course1.getId(), "2025-09-02");

  
    Grade grade1(student1.getId(), course1.getId(), '5');
    Grade grade2(student1.getId(), course2.getId(), '4');
    Grade grade3(student2.getId(), course1.getId(), '3');


    Schedule schedule1(course1.getId(), "Понедельник", "09:00-10:30", "Аудитория 101");
    Schedule schedule2(course1.getId(), "Среда", "09:00-10:30", "Аудитория 101");
    Schedule schedule3(course2.getId(), "Вторник", "11:00-12:30", "Аудитория 205");

    vector<Enrollment> enrollments = { enrollment1, enrollment2, enrollment3 };
    vector<Grade> grades = { grade1, grade2, grade3 };
    vector<Course> courses = { course1, course2 };

 

    ReportGenerator::generateStudentReport(student1, enrollments, grades, courses);

    cout << endl;

    ReportGenerator::generateStudentReport(student2, enrollments, grades, courses);


    Product p1("p1", "Смартфон", 29999.99, 10);
    Product p2("p2", "Ноутбук", 59999.99, 5);
    Product p3("p3", "Наушники", 4999.99, 20);


    Customer customer("c1", "Иван Иванов", "ул. Пушкина, д.10");

   
    ShoppingCart cart(customer.getId());
    cart.addItem(p1.getId(), 1);
    cart.addItem(p3.getId(), 2);

   
    vector<pair<string, int>> orderItems;
    for (const auto& item : cart.getItems()) {
        orderItems.emplace_back(item.first, item.second);
    }
    Order order("o1", customer.getId(), orderItems);

  
    double totalAmount = 0;
    for (const auto& item : order.getItems()) {
        if (item.first == p1.getId()) totalAmount += p1.getPrice() * item.second;
        else if (item.first == p2.getId()) totalAmount += p2.getPrice() * item.second;
        else if (item.first == p3.getId()) totalAmount += p3.getPrice() * item.second;
    }
    Payment payment("pay1", order.getId(), totalAmount);
    payment.processPayment();
    order.setPayment(payment.getId());


    Shipping shipping("ship1", order.getId(), customer.getAddress());
    shipping.shipOrder();
    order.setShipping(shipping.getId());


    order.completeOrder();
    customer.addOrder(order.getId());

    
    cout << "Информация о заказе #" << order.getId() << ":" << endl;
    cout << "Статус: " << order.getStatus() << endl;
    cout << "Товары:" << endl;
    for (const auto& item : order.getItems()) {
        if (item.first == p1.getId())
            cout << "- " << p1.getName() << " (" << item.second << " шт.)" << endl;
        else if (item.first == p2.getId())
            cout << "- " << p2.getName() << " (" << item.second << " шт.)" << endl;
        else if (item.first == p3.getId())
            cout << "- " << p3.getName() << " (" << item.second << " шт.)" << endl;
    }
    cout << "Сумма: " << payment.getAmount() << " руб." << endl;
    cout << "Статус оплаты: " << payment.getStatus() << endl;
    cout << "Статус доставки: " << shipping.getStatus() << endl;
    Library library;


    library.addBook(Book("b1", "Война и мир", "Лев Толстой", "978-5-389-06256-6"));
    library.addBook(Book("b2", "Преступление и наказание", "Федор Достоевский", "978-5-17-090831-3"));
    library.addBook(Book("b3", "Мастер и Маргарита", "Михаил Булгаков", "978-5-17-067842-0"));


    library.addUser(User1("u1", "Алексей Петров", "alex@example.com"));
    library.addUser(User1("u2", "Елена Смирнова", "elena@example.com"));


    library.borrowBook("b1", "u1");


    if (!library.borrowBook("b1", "u2")) {
        cout << "Книга уже взята другим пользователем" << endl;
    }

    library.reserveBook("b1", "u2");

  
    cout << "Результаты поиска по 'Толстой':" << endl;
    for (const auto& book : library.searchBooks("Толстой")) {
        cout << "- " << book.getTitle() << " (" << book.getAuthor() << ")"
            << (book.isAvailable() ? " Доступна" : " На руках") << endl;
    }

  
    library.returnBook("b1");
}