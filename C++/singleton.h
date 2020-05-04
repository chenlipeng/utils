#ifndef __SIGLETON_H_
#define __SIGLETON_H_

class Singleton {
private:
	static Singleton *instance;

	Singleton();
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);
public:
    /**
 	** @return: The same instance of this class every time
 	**/
    static Singleton* getInstance();
};

#endif //
