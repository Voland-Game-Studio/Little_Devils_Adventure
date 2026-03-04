import arcade
... # import of the main window class


def main():
    # Initialising main window
    window = ...()
    window.setup()

    # Showing first view
    window.switch_view("start")

    # Starting main cycle
    arcade.run()


if __name__ == "__main__":
    main()
