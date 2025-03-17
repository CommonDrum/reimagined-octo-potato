#ifndef GAME_H
#define GAME_H

class Game{
  private:

  public:
    Game();
    ~Game();
    void Init();
    void Run();
    void Destroy();

    void ProcessInput();
    void Update();
};

#endif // !GAME_H

