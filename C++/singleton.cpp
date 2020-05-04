#include "singleton.h"

Singleton::Singleton() {
}

Singleton::Singleton(const Singleton&) {
}

Singleton& Singleton::operator=(const Singleton&) {
}

Singleton* Singleton::instance = new Singleton();

Singleton* Singleton::getInstance(){
	return instance;
}
