#define WIN32_LEAN_AND_MEAN

#include<Windows.h>
#include<sstream>
using std::stringstream;

// Cria uma janela que calcula a resolução do monitor e mostra o resultado.
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	                 _In_opt_ HINSTANCE	hPrevInstance,
	                 _In_ LPSTR lpCmdLine,
	                 _In_ int nCmdShow)
{
	int resp = MessageBox(NULL,
				"Vamos Calcular o tamanho da tela?",
				"Mensagem",
				MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION);
	if (resp == IDYES)
	{
		// variaveis que armazenam o tamanho dos eixos x e y.
		int cxScreen = GetSystemMetrics(SM_CXSCREEN);
		int cyScreen = GetSystemMetrics(SM_CYSCREEN);

		stringstream text;
		text << "Resolução: " << cxScreen << " x " << cyScreen;

		MessageBox(NULL,
					text.str().c_str(),
					"Tamanho da tela.",
					MB_OK | MB_ICONINFORMATION);



	}else {

		MessageBox(NULL,
			       "Um jogo deve conhecer o tamanho da tela!",
					"Mensagem",
					MB_OK | MB_ICONWARNING);
	}
	return 0;
}