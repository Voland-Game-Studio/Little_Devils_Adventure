class Game {
private:
    bool running = false;
    InputSystem inputSystem;
    PhysicsSystem physicsSystem;
    RenderSystem renderSystem;
    AudioSystem audioSystem;

    // Фиксированный временной шаг для физики
    const double fixedTimeStep = 1.0 / 60.0;
    double accumulator = 0.0;
public:
    // Инициализация подсистем
    void Initialize() {
        inputSystem.Initialize();
        physicsSystem.Initialize();
        renderSystem.Initialize();
        audioSystem.Initialize();

        running = true;
    }

    void Run() {
        double previousTime = GetCurrentTime();

        while (running) {
            double currentTime = GetCurrentTime();
            double deltaTime = currentTime – previousTime;
            previousTime = currentTime;

            // Ограничиваем deltaTime для предотвращения "спирали смерти"
            if (deltaTime > 0.25) deltaTime = 0.25;

            accumulator += deltaTime;

            // Обработка ввода
            inputSystem.ProcessInput();
            if (inputSystem.IsQuitRequested()) {
                running = false;
                continue;
            }

            // Фиксированный временной шаг для физики
            while (accumulator >= fixedTimeStep) {
                physicsSystem.Update(fixedTimeStep);
                accumulator -= fixedTimeStep;
            }

            // Обновление игровой логики
            UpdateGameLogic(deltaTime);

            // Обновление аудио
            audioSystem.Update(deltaTime);

            // Отрисовка
            renderSystem.Render();
        }
    }

    void Shutdown() {
        audioSystem.Shutdown();
        renderSystem.Shutdown();
        physicsSystem.Shutdown();
        inputSystem.Shutdown();
    }

private:
    double GetCurrentTime() {
    // Реализация получения текущего времени с высокой точностью
    }

    void UpdateGameLogic(double deltaTime) {
    // Обновление состояния игровых объектов
    }
};

