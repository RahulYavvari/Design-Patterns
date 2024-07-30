#include <iostream>
#include <string>

class Button {
public:
	std::string textContent;
	virtual void render() = 0;
	virtual void onClick() = 0;
};

class WindowsButton : public Button {
public:
	WindowsButton(std::string p_textContent) {
		textContent = p_textContent;
	};

	void render() {
		std::cout << "[ " << textContent << " ]" << std::endl;
	}

	void onClick() {
		std::cout << "[WINDOWS_EVENT_LISTENER] Button Clicked " << std::endl;
	}
};

class LinuxButton : public Button {
public:
	LinuxButton(std::string p_textContent) {
		textContent = p_textContent;
	};

	void render() {
		std::cout << "( " << textContent << " )" << std::endl;
	}

	void onClick() {
		std::cout << "[LINUX_EVENT_LISTENER] Button Clicked " << std::endl;
	}
};

class Dialog {
public:
	virtual Button* factoryMethod() = 0;
};

class WindowsDialog : public Dialog {
public:
	Button* newButton = nullptr;
	Button* factoryMethod() {
		newButton = new WindowsButton("Submit");
		return newButton;
	}

	~WindowsDialog() {
		delete newButton;
	}
};

class LinuxDialog : public Dialog {
public:
	Button* newButton = nullptr;
	Button* factoryMethod() {
		newButton = new LinuxButton("Submit");
		return newButton;
	}

	~LinuxDialog() {
		delete newButton;
	}
};

int main()
{
	WindowsDialog WindowsDialogFactory;
	LinuxDialog LinuxDialogFactory;

	std::cout << "\nWINDOWS 1.1" << std::endl;
	Button* btn1 = WindowsDialogFactory.factoryMethod();
	btn1->render();
	btn1->onClick();

	std::cout << "\nLINUX 1.1.1" << std::endl;
	Button* btn2 = LinuxDialogFactory.factoryMethod();
	btn2->render();
	btn2->onClick();

	return 0;
}