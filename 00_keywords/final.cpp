class Super1 final {};

class Son1 : public Super1 {};

class Super2 {
public:
	virtual void SomeMethod() final;
};

class Son2 : public Super2 {
	virtual void SomeMethod();
};

int main() {
	return 0;
}
