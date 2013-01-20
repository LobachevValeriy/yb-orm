#include <memory>
#include <iostream>
#include <orm/SchemaSingleton.h>
#include "domain/Client.h"
using namespace std;

int main()
{
    try {
        auto_ptr<Yb::SqlConnection> conn(new Yb::SqlConnection(
                    "sqlite+sqlite://c:/yborm/examples/test1_db"));
        Yb::Engine engine(Yb::Engine::READ_WRITE, conn);
        engine.create_schema(Yb::init_schema(), true);
        Yb::Session session(Yb::theSchema::instance(), &engine);

        Domain::Client client;
        string name, email, budget;
        cout << "Enter name, email, budget:\n";
        cin >> name >> email >> budget;
        client.name = name;
        client.email = email;
        client.budget = Yb::Decimal(budget);
        client.dt = Yb::now();
        client.save(session);
        session.flush();
        cout << "New client: " << client.id.value() << endl;
        engine.commit();
        return 0;
    }
    catch (const std::exception &ex) {
        cout << "exception: " << ex.what() << endl;
        return 1;
    }
}
 
