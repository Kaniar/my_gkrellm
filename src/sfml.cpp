//
// sfml.cpp for sfml in /home/dubois_v/Piscine/Rush/cpp_gkrellm/sfml
// 
// Made by Benjamin Dubois
// Login   <dubois_v@epitech.net>
// 
// Started on  Sat Jan 21 22:23:03 2017 Benjamin Dubois
// Last update Sun Jan 22 10:00:40 2017 Romain Kania
//

#include    <SFML/Graphics.hpp>
#include    <SFML/Window.hpp>
#include    <string>
#include    <vector>
#include    "sfml.hpp"
#include    "ModuleName.hpp"
#include    "ModuleOS.hpp"
#include    "ModuleRam.hpp"
#include    "ModuleTime.hpp"
#include    "ModuleCpu.hpp"

using namespace std;
using namespace sf;

void                drawCPU(ModuleCpu const &cpu, Font const &font, float width,
                            RenderWindow &window)
{
    int		        x = 1;
    int             nb;
    std::vector<float>percentage = cpu.getPercent();
    for (std::vector<float>::iterator it = percentage.begin() ; it != percentage.end(); ++it) {
        int             nb_bar = 0;
        Text    memText(to_string(x) + "[ ", font);
        memText.setColor(Color(0,200,0));
        memText.setCharacterSize(20);
        if (x == 1)
            memText.setPosition(0, (width) * (x + 4.3) + (11 * (x + 4.6)));
        else
            memText.setPosition(0, (width) * (x + 4.2) + (11 * (x + 4)));
        window.draw(memText);
        std::string     pipe;
        nb = static_cast<int>(*it);
        nb = 58 * nb / 100;
        for (; nb_bar < nb; ++nb_bar) {
            pipe += "| ";
        }
        Text    redText(pipe, font);
        redText.setCharacterSize(16);
        redText.setColor(Color::Red);
        if (x == 1)
        redText.setPosition(20, (width) * (x + 4.3) + (12 * (x + 4.3)));
        else
            redText.setPosition(20, (width) * (x + 4.1) + (12 * (x + 4)));
        window.draw(redText);
        pipe = "";
        for (; nb_bar < 59; ++nb_bar) {
            pipe += "| ";
        }
        Text    greenText(pipe, font);
        greenText.setCharacterSize(16);
        greenText.setColor(Color::Green);
        if (x == 1)
            greenText.setPosition(nb * 8 + 21, (width) * (x + 4.3) + (12 * (x + 4.3)));
        else
            greenText.setPosition(nb * 8 + 21, (width) * (x + 4.1) + (12 * (x + 4)));
        window.draw(greenText);
        Text    memText2("] " + to_string(static_cast<unsigned int>(*it)) + "%", font);
        memText2.setColor(Color(0,200,0));
        memText2.setCharacterSize(20);
        if (x == 1)
            memText2.setPosition(nb_bar * 8 + 20, (width) * (x + 4.3) + (11 * (x + 4.6)));
        else
            memText2.setPosition(nb_bar * 8 + 20, (width) * (x + 4.2) + (11 * (x + 4)));
        window.draw(memText2);
        x++;
    }
}

void                drawRam(ModuleRam const &ram, Font const &font, float width,
			    RenderWindow &window)
{
  int             total = ram.getTotMem();
  int             used = ram.getUsedMem();
  int		        nbofpipe = 58 * used / total;
  int		        x = 2;

    Text    memText("Mem[ ", font);
    memText.setColor(Color(0,200,0));
    memText.setCharacterSize(20);
    memText.setPosition(0, (width) * 4 + (11 * 4));
    window.draw(memText);
  std::string     pipe;
  for (; x < nbofpipe; ++x) {
    pipe += "| ";
  }
  Text    redText(pipe, font);
  redText.setCharacterSize(16);
  redText.setColor(Color::Red);
  redText.setPosition(50, (width) * 4 + (12 * 4));
  window.draw(redText);
  pipe = "";
  for (; x < 59; ++x) {
    pipe += "| ";
  }
  Text    greenText(pipe, font);
  greenText.setCharacterSize(16);
  greenText.setColor(Color::Green);
  greenText.setPosition(nbofpipe * 7 + 42, (width) * 4 + (12 * 4));
  window.draw(greenText);

    Text    memText2("]" + to_string(used) + "/" + to_string(total) + "Ko", font);
    memText2.setColor(Color(0,200,0));
    memText2.setCharacterSize(20);
    memText2.setPosition(x * 8 + 30, (width) * 4 + (11 * 4));
    window.draw(memText2);
}

vector<Text>    &setText(vector<string> &currentModule, vector<Text> &text,
                             Font const &font, float width, int nb)
{
  static int i = -1;
  for (vector<std::string>::iterator k = currentModule.begin(); k != currentModule.end(); ++k) {
    Text yolo(*k, font);
    yolo.setCharacterSize(16);
    if (i >= 4){
      text.pop_back();
    } else i++;
    text.push_back(yolo);
    text[i].setPosition(0, (width) * nb + (10 * nb));
    nb++;
  }
  return text;
}

int    sfml()
{
    ModuleOS os;
    ModuleName name;
    RenderWindow window(VideoMode(800, 600), "gkrellm", Style::Default);
    View    view;
    view.reset(FloatRect(0, 0, 0.5, 1));
    Texture texture;
    Texture textureCross;
    Font    font;
    if (!font.loadFromFile("src/arial.ttf"))
        return -1;
    Text tmp("YOLO", font);
    tmp.setCharacterSize(16);
    float width = tmp.getLocalBounds().width;
    bool    instance = true;
    vector<bool>         blackTab(6, true);
    RectangleShape  closeCross(Vector2f(30, 30));
    RectangleShape rectangle(Vector2f(VideoMode::getDesktopMode().width, width * 2));
    RectangleShape blackRectangle(Vector2f(VideoMode::getDesktopMode().width, width * 2));
    blackRectangle.setFillColor(Color::Black);
    vector<string>     currentModule;
    vector<Text>    text;
    int max = VideoMode::getDesktopMode().width;
    if (!texture.loadFromFile("src/wallpaper1.jpg", IntRect(0, 0, max, width * 2)))
      return -1;
    if (!textureCross.loadFromFile("src/images.jpg", IntRect(0, 0, 102, 102)))
        return -1;
    while (window.isOpen())
    {
        if (instance)
        {
            closeCross.setTexture(&textureCross);
            rectangle.setTexture(&texture);
            currentModule = name.getData();
            text = setText(currentModule, text, font, width, 0);
            currentModule = os.getData();
            text = setText(currentModule, text, font, width, 2);
            instance = false;
        }
        for (int j = 0; j < 6; ++j) {
            closeCross.setPosition(max - 30, (width * 2) * j + (10 * j));
            rectangle.setPosition(0, (width * 2) * j + (10 * j));
            window.draw(rectangle);
            window.draw(closeCross);
        }
        ModuleRam ram;
      drawRam(ram, font, width, window);
        ModuleCpu cpu;
      drawCPU(cpu, font, width, window);
      ModuleTime time;
      currentModule = time.getData();
      text = setText(currentModule, text, font, width, 10);
      Event event;
      while (window.pollEvent(event))
        {
	  if (event.type == Event::Resized) {
          window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
          max = event.size.width;
      }
          if (event.type == Event::MouseButtonPressed)
      {
          if (event.mouseButton.x >= max - 30 && event.mouseButton.x <= max)
              for (int m = 0; m < 6; ++m)
                  if (event.mouseButton.y >= (width * 2) * m + (10 * m) && event.mouseButton.y <= (width * 2) * m + (10 * m) + 30)
                      blackTab[m] = !blackTab[m];
      }
	  if (event.type == Event::Closed)
	    window.close();
        }
      for (vector<Text>::iterator l = text.begin(); l != text.end(); ++l) {
          window.draw(*l);
      }
        for (int i = 0; i < 6; ++i) {
            if (!blackTab[i]) {
                closeCross.setPosition(max - 30, (width * 2) * i + (10 * i));
                blackRectangle.setPosition(0, (width * 2) * i + (10 * i));
                window.draw(blackRectangle);
                window.draw(closeCross);
            }
        }
      window.display();
      window.clear();
    }
  return 0;
}
