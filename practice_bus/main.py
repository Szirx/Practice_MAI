import graphics as gr
from abc import ABC, abstractmethod


class Location(ABC):
    """Класс Location с геттерами protected полей x и y,
        в класс Location наследуется класс ABC,для того,
        чтобы определить в иерархии абстрактный класс и
        интерфейс"""
    def __init__(self, init_x, init_y):
        self._x = init_x
        self._y = init_y

    def __del__(self):
        pass

    def get_x(self):
        return self._x

    def get_y(self):
        return self._y


class Point(Location):
    """Класс Point потомок класса Location с методами показа/сокрытия(show/hide) фигуры
     и методом движения move_to"""
    def __init__(self, init_x, init_y):
        """метод super() в классе нужен для того, чтобы наследовать поля родительских классов
        и вызывать их методы"""
        super().__init__(init_x, init_y)
        self._visible = False

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        point = gr.Point(self._x, self._y)
        point.setFill('black')
        point.draw(window)

    def hide(self):
        self._visible = False
        point = gr.Point(self._x, self._y)
        point.setFill('white')
        point.draw(window)

    def is_visible(self):
        return self._visible

    def move_to(self, new_x, new_y):
        self.hide()
        self._x = new_x
        self._y = new_y
        self.show()


class AbsBody(Point):
    """абстрактный класс AbsBody"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y)
        self._radius = init_radius

    @abstractmethod
    def __del__(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def hide(self):
        pass

    @abstractmethod
    def get_width(self):
        pass

    @abstractmethod
    def get_height(self):
        pass


class Body(AbsBody):
    """Класс каркаса транспорта"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)
        self._width = 720
        self._height = 330
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height

    def __del__(self):
        pass

    def show(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = True
        # Разрисовка происходит следующим образом:
        # 1) создается объект класса фигуры
        # 2) окрашивается его контур (setOutline) и внутренность (setFill)
        body = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        body.setOutline('black')
        body.setFill('white')

        window1 = gr.Rectangle(gr.Point(self._x + 20, self._y + 20), gr.Point(self._x + 140, self._y + 140))
        window1.setOutline('black')

        window2 = gr.Rectangle(gr.Point(self._x + 300, self._y + 20), gr.Point(self._x + 420, self._y + 140))
        window2.setOutline('black')

        window3 = gr.Rectangle(gr.Point(self._x + 580, self._y + 20), gr.Point(self._x + 700, self._y + 140))
        window3.setOutline('black')

        door1 = gr.Rectangle(gr.Point(self._x + 440, self._y + 20), gr.Point(self._x + 560, self._y + 310))
        door1.setOutline('black')

        door2 = gr.Rectangle(gr.Point(self._x + 460, self._y + 40), gr.Point(self._x + 540, self._y + 120))
        door2.setOutline('black')

        head_light1 = gr.Circle(gr.Point(self._x + 20, self._y + 210), self._radius)
        head_light1.setOutline('black')

        head_light2 = gr.Circle(gr.Point(self._x + 20, self._y + 240), self._radius)
        head_light2.setOutline('black')

        head_light3 = gr.Circle(gr.Point(self._x + 20, self._y + 270), self._radius)
        head_light3.setOutline('black')

        head_light4 = gr.Circle(gr.Point(self._x2 - 20, self._y2 - 70), self._radius)
        head_light4.setOutline('black')

        # Этот участок кода нужен для того, чтобы фигуры показывались в окне
        body.draw(window)
        window1.draw(window)
        window2.draw(window)
        window3.draw(window)
        door1.draw(window)
        door2.draw(window)
        head_light1.draw(window)
        head_light2.draw(window)
        head_light3.draw(window)
        head_light4.draw(window)

    def hide(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = True

        body = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        body.setOutline('white')
        body.setFill('white')

        window1 = gr.Rectangle(gr.Point(self._x + 20, self._y + 20), gr.Point(self._x + 140, self._y + 140))
        window1.setOutline('white')

        window2 = gr.Rectangle(gr.Point(self._x + 300, self._y + 20), gr.Point(self._x + 420, self._y + 140))
        window2.setOutline('white')

        window3 = gr.Rectangle(gr.Point(self._x + 580, self._y + 20), gr.Point(self._x + 700, self._y + 140))
        window3.setOutline('white')

        door1 = gr.Rectangle(gr.Point(self._x + 440, self._y + 20), gr.Point(self._x + 560, self._y + 310))
        door1.setOutline('white')

        door2 = gr.Rectangle(gr.Point(self._x + 460, self._y + 40), gr.Point(self._x + 540, self._y + 120))
        door2.setOutline('white')

        head_light1 = gr.Circle(gr.Point(self._x + 20, self._y + 210), self._radius)
        head_light1.setOutline('white')

        head_light2 = gr.Circle(gr.Point(self._x + 20, self._y + 240), self._radius)
        head_light2.setOutline('white')

        head_light3 = gr.Circle(gr.Point(self._x + 20, self._y + 270), self._radius)
        head_light3.setOutline('white')

        head_light4 = gr.Circle(gr.Point(self._x2 - 20, self._y2 - 70), self._radius)
        head_light4.setOutline('white')

        body.draw(window)
        window1.draw(window)
        window2.draw(window)
        window3.draw(window)
        door1.draw(window)
        door2.draw(window)
        head_light1.draw(window)
        head_light2.draw(window)
        head_light3.draw(window)
        head_light4.draw(window)

    def get_width(self):
        return self._width

    def get_height(self):
        return self._height


class Bus(Body):
    """Класс автобуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)
        self._radius = 10

    def __del__(self):
        pass

    def show(self):
        super(Bus, self).show()

        self._visible = True
        window1 = gr.Rectangle(gr.Point(self._x + 160, self._y + 20), gr.Point(self._x + 280, self._y + 140))

        wheel1 = gr.Circle(gr.Point(self._x + 140, self._y2), self._radius * 5.5)
        wheel1.setFill('white')

        wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 5.5)
        wheel2.setFill('white')

        wheel3 = gr.Circle(gr.Point(self._x + 140, self._y2), self._radius * 4.5)
        wheel3.setFill('white')

        wheel4 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel4.setFill('white')

        window1.draw(window)
        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)

    def hide(self):
        super(Bus, self).hide()

        self._visible = False
        window1 = gr.Rectangle(gr.Point(self._x + 160, self._y2 + 20), gr.Point(self._x + 280, self._y + 140))
        window1.setOutline('white')

        wheel1 = gr.Circle(gr.Point(self._x + 140, self._y2), self._radius * 5.5)
        wheel1.setFill('white')
        wheel1.setOutline('white')

        wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 5.5)
        wheel2.setFill('white')
        wheel2.setOutline('white')

        wheel3 = gr.Circle(gr.Point(self._x + 140, self._y2), self._radius * 4.5)
        wheel3.setFill('white')
        wheel3.setOutline('white')

        wheel4 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel4.setFill('white')
        wheel4.setOutline('white')

        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)


class CrashedBus(Bus):
    """Класс разбитого автобуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        super(CrashedBus, self).show()
        self._visible = True

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('gray')
        smoke1.setFill('gray')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('gray')
        smoke2.setFill('gray')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('gray')
        smoke3.setFill('gray')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)

    def hide(self):
        super(CrashedBus, self).hide()
        self._visible = False

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')
        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')
        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('white')
        smoke1.setFill('white')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('white')
        smoke2.setFill('white')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('white')
        smoke3.setFill('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)


class BrokenBus(Bus):
    """Класс сломанного автобуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        super(BrokenBus, self).show()
        self._visible = True

        erase_wheel1 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 5.5)
        erase_wheel1.setFill('white')
        erase_wheel1.setOutline('white')

        erase_wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        erase_wheel2.setFill('white')
        erase_wheel2.setOutline('white')

        erase_head_light = gr.Circle(gr.Point(self._x2 - 20, self._y2 - 30), self._radius)

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))

        emptiness = gr.Line(gr.Point(self._x2 - 155, self._y2), gr.Point(self._x2 - 45, self._y2))

        erase_wheel1.draw(window)
        erase_wheel2.draw(window)
        erase_head_light.draw(window)
        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness.draw(window)

    def hide(self):
        super(BrokenBus, self).hide()
        self._visible = False

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        emptiness = gr.Line(gr.Point(self._x2 - 155, self._y2), gr.Point(self._x2 - 45, self._y2))
        emptiness.setOutline('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness.draw(window)


class Tramway(Body):
    """Класс трамвая"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(Tramway, self).show()
        door1 = gr.Rectangle(gr.Point(self._x + 160, self._y + 20), gr.Point(self._x + 280, self._y + 310))
        door2 = gr.Rectangle(gr.Point(self._x + 180, self._y + 40), gr.Point(self._x + 260, self._y + 120))

        wheel1 = gr.Circle(gr.Point(self._x + 50, self._y2), self._radius * 3.0)
        wheel1.setFill('white')

        wheel2 = gr.Circle(gr.Point(self._x + 110, self._y2), self._radius * 3.0)
        wheel2.setFill('white')

        wheel3 = gr.Circle(gr.Point(self._x + 330, self._y2), self._radius * 3.0)
        wheel3.setFill('white')

        wheel4 = gr.Circle(gr.Point(self._x + 610, self._y2), self._radius * 3.0)
        wheel4.setFill('white')

        wheel5 = gr.Circle(gr.Point(self._x + 670, self._y2), self._radius * 3.0)
        wheel5.setFill('white')

        horn1 = gr.Line(gr.Point(self._x + 300, self._y), gr.Point(self._x + 360, self._y - 60))
        horn2 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 260, self._y - 80))
        horn3 = gr.Line(gr.Point(self._x + 260, self._y - 80), gr.Point(self._x + 360, self._y - 100))
        horn4 = gr.Line(gr.Point(self._x + 360, self._y - 100), gr.Point(self._x + 460, self._y - 80))
        horn5 = gr.Line(gr.Point(self._x + 460, self._y - 80), gr.Point(self._x + 360, self._y - 60))
        horn6 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 420, self._y))

        door1.draw(window)
        door2.draw(window)
        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)
        wheel5.draw(window)
        horn1.draw(window)
        horn2.draw(window)
        horn3.draw(window)
        horn4.draw(window)
        horn5.draw(window)
        horn6.draw(window)

    def hide(self):
        self._visible = False
        super(Tramway, self).hide()
        door1 = gr.Rectangle(gr.Point(self._x + 160, self._y + 20), gr.Point(self._x + 280, self._y + 310))
        door1.setOutline('white')

        door2 = gr.Rectangle(gr.Point(self._x + 180, self._y + 40), gr.Point(self._x + 260, self._y + 120))
        door2.setOutline('white')

        wheel1 = gr.Circle(gr.Point(self._x + 50, self._y2), self._radius * 3.0)
        wheel1.setFill('white')
        wheel1.setOutline('white')

        wheel2 = gr.Circle(gr.Point(self._x + 110, self._y2), self._radius * 3.0)
        wheel2.setFill('white')
        wheel2.setOutline('white')

        wheel3 = gr.Circle(gr.Point(self._x + 330, self._y2), self._radius * 3.0)
        wheel3.setFill('white')
        wheel3.setOutline('white')

        wheel4 = gr.Circle(gr.Point(self._x + 610, self._y2), self._radius * 3.0)
        wheel4.setFill('white')
        wheel4.setOutline('white')

        wheel5 = gr.Circle(gr.Point(self._x + 670, self._y2), self._radius * 3.0)
        wheel5.setFill('white')
        wheel5.setOutline('white')

        horn1 = gr.Line(gr.Point(self._x + 300, self._y), gr.Point(self._x + 360, self._y - 60))
        horn1.setOutline('white')

        horn2 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 260, self._y - 80))
        horn2.setOutline('white')

        horn3 = gr.Line(gr.Point(self._x + 260, self._y - 80), gr.Point(self._x + 360, self._y - 100))
        horn3.setOutline('white')

        horn4 = gr.Line(gr.Point(self._x + 360, self._y - 100), gr.Point(self._x + 460, self._y - 80))
        horn4.setOutline('white')

        horn5 = gr.Line(gr.Point(self._x + 460, self._y - 80), gr.Point(self._x + 360, self._y - 60))
        horn5.setOutline('white')

        horn6 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 420, self._y))
        horn6.setOutline('white')

        door1.draw(window)
        door2.draw(window)
        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)
        wheel5.draw(window)
        horn1.draw(window)
        horn2.draw(window)
        horn3.draw(window)
        horn4.draw(window)
        horn5.draw(window)
        horn6.draw(window)


class CrashedTramway(Tramway):
    """Класс разбитого трамвая"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(CrashedTramway, self).show()
        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('gray')
        smoke1.setFill('gray')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('gray')
        smoke2.setFill('gray')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('gray')
        smoke3.setFill('gray')

        horn1 = gr.Line(gr.Point(self._x + 300, self._y), gr.Point(self._x + 360, self._y - 60))
        horn1.setOutline('white')

        horn2 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 260, self._y - 80))
        horn2.setOutline('white')

        horn3 = gr.Line(gr.Point(self._x + 260, self._y - 80), gr.Point(self._x + 360, self._y - 100))
        horn3.setOutline('white')

        horn4 = gr.Line(gr.Point(self._x + 360, self._y - 100), gr.Point(self._x + 460, self._y - 80))
        horn4.setOutline('white')

        horn5 = gr.Line(gr.Point(self._x + 460, self._y - 80), gr.Point(self._x + 360, self._y - 60))
        horn5.setOutline('white')

        horn6 = gr.Line(gr.Point(self._x + 360, self._y - 60), gr.Point(self._x + 420, self._y))
        horn6.setOutline('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)
        horn1.draw(window)
        horn2.draw(window)
        horn3.draw(window)
        horn4.draw(window)
        horn5.draw(window)
        horn6.draw(window)

    def hide(self):
        self._visible = False
        super(CrashedTramway, self).hide()

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('white')
        smoke1.setFill('white')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('white')
        smoke2.setFill('white')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('white')
        smoke3.setFill('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)


class BrokenTramway(Tramway):
    """Класс сломанного трамвая"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        super(BrokenTramway, self).show()

        head_light4 = gr.Circle(gr.Point(self._x2 - 20, self._y2 - 70), self._radius)
        head_light4.setOutline('white')

        wheel5 = gr.Circle(gr.Point(self._x + 670, self._y2), self._radius * 3.0)
        wheel5.setOutline('white')

        wheel3 = gr.Circle(gr.Point(self._x + 330, self._y2), self._radius * 3.0)
        wheel3.setOutline('white')

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('black')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('black')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('black')

        emptiness1 = gr.Line(gr.Point(self._x + 640, self._y2), gr.Point(self._x + 700, self._y2))
        emptiness2 = gr.Line(gr.Point(self._x + 360, self._y2), gr.Point(self._x + 300, self._y2))

        head_light4.draw(window)
        wheel3.draw(window)
        wheel5.draw(window)
        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness1.draw(window)
        emptiness2.draw(window)

    def hide(self):
        super(BrokenTramway, self).hide()

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        emptiness1 = gr.Line(gr.Point(self._x + 640, self._y2), gr.Point(self._x + 700, self._y2))
        emptiness1.setOutline('white')

        emptiness2 = gr.Line(gr.Point(self._x + 360, self._y2), gr.Point(self._x + 300, self._y2))
        emptiness2.setOutline('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness1.draw(window)
        emptiness2.draw(window)


class Trolleybus(Body):
    """Класс троллейбуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = True
        super(Trolleybus, self).show()

        door1 = gr.Rectangle(gr.Point(self._x + 160, self._y + 20), gr.Point(self._x + 280, self._y + 310))
        door2 = gr.Rectangle(gr.Point(self._x + 180, self._y + 40), gr.Point(self._x + 260, self._y + 120))

        wheel1 = gr.Circle(gr.Point(self._x + 80, self._y2), self._radius * 4.5)
        wheel1.setFill('white')

        wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel2.setFill('white')

        wheel3 = gr.Circle(gr.Point(self._x + 80, self._y2), self._radius * 4.5)
        wheel3.setFill('white')

        wheel4 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel4.setFill('white')

        horn1 = gr.Line(gr.Point(self._x + 670, self._y), gr.Point(self._x + 570, self._y - 120))
        horn2 = gr.Line(gr.Point(self._x + 610, self._y), gr.Point(self._x + 510, self._y - 120))

        door1.draw(window)
        door2.draw(window)
        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)
        horn1.draw(window)
        horn2.draw(window)

    def hide(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = False
        super(Trolleybus, self).hide()

        door1 = gr.Rectangle(gr.Point(self._x + 160, self._y + 20), gr.Point(self._x + 280, self._y + 310))
        door1.setOutline('white')

        door2 = gr.Rectangle(gr.Point(self._x + 180, self._y + 40), gr.Point(self._x + 260, self._y + 120))
        door2.setOutline('white')

        wheel1 = gr.Circle(gr.Point(self._x + 80, self._y2), self._radius * 4.5)
        wheel1.setFill('white')
        wheel1.setOutline('white')

        wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel2.setFill('white')
        wheel2.setOutline('white')

        wheel3 = gr.Circle(gr.Point(self._x + 80, self._y2), self._radius * 4.5)
        wheel3.setFill('white')
        wheel3.setOutline('white')

        wheel4 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        wheel4.setFill('white')
        wheel4.setOutline('white')

        horn1 = gr.Line(gr.Point(self._x + 670, self._y), gr.Point(self._x + 570, self._y - 120))
        horn1.setOutline('white')

        horn2 = gr.Line(gr.Point(self._x + 610, self._y), gr.Point(self._x + 510, self._y - 120))
        horn2.setOutline('white')

        door1.draw(window)
        door2.draw(window)
        wheel1.draw(window)
        wheel2.draw(window)
        wheel3.draw(window)
        wheel4.draw(window)
        horn1.draw(window)
        horn2.draw(window)


class CrashedTrolleybus(Bus):
    """Класс разбитого троллейбуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(CrashedTrolleybus, self).show()

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('gray')
        smoke1.setFill('gray')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('gray')
        smoke2.setFill('gray')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('gray')
        smoke3.setFill('gray')

        horn = gr.Line(gr.Point(self._x + 670, self._y), gr.Point(self._x + 570, self._y - 120))
        horn.setOutline('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)
        horn.draw(window)

    def hide(self):
        super(CrashedTrolleybus, self).hide()
        self._visible = False

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        smoke1 = gr.Circle(gr.Point(self._x2 - 200, self._y2 - 60), self._radius * 10.0)
        smoke1.setOutline('white')
        smoke1.setFill('white')

        smoke2 = gr.Circle(gr.Point(self._x2 - 210, self._y2 - 110), self._radius * 9.0)
        smoke2.setOutline('white')
        smoke2.setFill('white')

        smoke3 = gr.Circle(gr.Point(self._x2 - 275, self._y2 - 155), self._radius * 7.5)
        smoke3.setOutline('white')
        smoke3.setFill('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        smoke1.draw(window)
        smoke2.draw(window)
        smoke3.draw(window)


class BrokenTrolleybus(Bus):
    """Класс сломанного троллейбуса"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        super(BrokenTrolleybus, self).show()
        self._visible = True

        erase_wheel1 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 5.5)
        erase_wheel1.setFill('white')
        erase_wheel1.setOutline('white')

        erase_wheel2 = gr.Circle(gr.Point(self._x2 - 100, self._y2), self._radius * 4.5)
        erase_wheel2.setFill('white')
        erase_wheel2.setOutline('white')

        erase_head_light = gr.Circle(gr.Point(self._x2 - 20, self._y2 - 70), self._radius)
        erase_head_light.setFill('white')
        erase_head_light.setOutline('white')

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('black')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('black')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('black')

        emptiness = gr.Line(gr.Point(self._x2 - 155, self._y2), gr.Point(self._x2 - 45, self._y2))
        emptiness.setOutline('black')

        erase_wheel1.draw(window)
        erase_wheel2.draw(window)
        erase_head_light.draw(window)
        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness.draw(window)

    def hide(self):
        super(BrokenTrolleybus, self).hide()
        self._visible = False

        crack1 = gr.Line(gr.Point(self._x + 700, self._y + 20), gr.Point(self._x + 660, self._y + 60))
        crack1.setOutline('white')

        crack2 = gr.Line(gr.Point(self._x + 660, self._y + 60), gr.Point(self._x + 670, self._y + 60))
        crack2.setOutline('white')

        crack3 = gr.Line(gr.Point(self._x + 670, self._y + 60), gr.Point(self._x + 630, self._y + 100))
        crack3.setOutline('white')

        emptiness = gr.Line(gr.Point(self._x2 - 155, self._y2), gr.Point(self._x2 - 45, self._y2))
        emptiness.setOutline('white')

        crack1.draw(window)
        crack2.draw(window)
        crack3.draw(window)
        emptiness.draw(window)


class ITrash(Point):
    """Класс-Интерфейс ITrash"""
    def __init__(self, init_x, init_y):
        super().__init__(init_x, init_y)

    @abstractmethod
    def __del__(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def hide(self):
        pass

    @abstractmethod
    def get_width(self):
        pass

    @abstractmethod
    def get_height(self):
        pass


class Trash(ITrash):
    """Класс мусорного бака"""
    def __init__(self, init_x, init_y):
        super().__init__(init_x, init_y)
        self._width = 60
        self._height = 100
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height

    def __del__(self):
        pass

    def show(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height

        self._visible = True

        trash1 = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        trash2 = gr.Rectangle(gr.Point(self._x - 10, self._y - 10), gr.Point(self._x2 + 10, self._y))
        line1 = gr.Line(gr.Point(self._x + 15, self._y - 10), gr.Point(self._x + 15, self._y - 15))
        line2 = gr.Line(gr.Point(self._x + 15, self._y - 15), gr.Point(self._x + 45, self._y - 15))
        line3 = gr.Line(gr.Point(self._x + 45, self._y - 15), gr.Point(self._x + 45, self._y - 10))

        trash1.draw(window)
        trash2.draw(window)
        line1.draw(window)
        line2.draw(window)
        line3.draw(window)

    def hide(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height

        self._visible = True

        trash1 = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        trash1.setOutline('white')

        trash2 = gr.Rectangle(gr.Point(self._x - 10, self._y - 10), gr.Point(self._x2 + 10, self._y))
        trash2.setOutline('white')

        line1 = gr.Line(gr.Point(self._x + 15, self._y - 10), gr.Point(self._x + 15, self._y - 15))
        line1.setOutline('white')

        line2 = gr.Line(gr.Point(self._x + 15, self._y - 15), gr.Point(self._x + 45, self._y - 15))
        line2.setOutline('white')

        line3 = gr.Line(gr.Point(self._x + 45, self._y - 15), gr.Point(self._x + 45, self._y - 10))
        line3.setOutline('white')

        trash1.draw(window)
        trash2.draw(window)
        line1.draw(window)
        line2.draw(window)
        line3.draw(window)

    def get_width(self):
        return self._width

    def get_height(self):
        return self._height


class BigTrash(Trash):
    """Класс большого мусорного бака"""
    def __init__(self, init_x, init_y):
        super().__init__(init_x, init_y)
        self._width = 200
        self._height = 100
        self._radius = 5

    def __del__(self):
        pass

    def show(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = True

        body1 = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        body2 = gr.Rectangle(gr.Point(self._x - 10, self._y - 10), gr.Point(self._x2 + 10, self._y))
        line1 = gr.Line(gr.Point(self._x + 20, self._y + 20), gr.Point(self._x2 - 20, self._y2 - 20))
        line2 = gr.Line(gr.Point(self._x2 - 20, self._y + 20), gr.Point(self._x + 20, self._y2 - 20))
        circle1 = gr.Circle(gr.Point(self._x + 5, self._y2 + 5), self._radius)
        circle1.setFill('white')
        circle2 = gr.Circle(gr.Point(self._x2 - 5, self._y2 + 5), self._radius)
        circle2.setFill('white')

        body1.draw(window)
        body2.draw(window)
        line1.draw(window)
        line2.draw(window)
        circle1.draw(window)
        circle2.draw(window)

    def hide(self):
        self._x2 = self._x + self._width
        self._y2 = self._y + self._height
        self._visible = False

        body1 = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x2, self._y2))
        body1.setOutline('white')
        body2 = gr.Rectangle(gr.Point(self._x - 10, self._y - 10), gr.Point(self._x2 + 10, self._y))
        body2.setOutline('white')
        line1 = gr.Line(gr.Point(self._x + 20, self._y + 20), gr.Point(self._x2 - 20, self._y2 - 20))
        line1.setOutline('white')
        line2 = gr.Line(gr.Point(self._x2 - 20, self._y + 20), gr.Point(self._x + 20, self._y2 - 20))
        line2.setOutline('white')
        circle1 = gr.Circle(gr.Point(self._x + 5, self._y2 + 5), self._radius)
        circle1.setOutline('white')
        circle1.setFill('white')
        circle2 = gr.Circle(gr.Point(self._x2 - 5, self._y2 + 5), self._radius)
        circle2.setOutline('white')
        circle2.setFill('white')

        body1.draw(window)
        body2.draw(window)
        line1.draw(window)
        line2.draw(window)
        circle1.draw(window)
        circle2.draw(window)


def is_collision(transport, trash):
    """Функция столкновения двух сценовых объектов"""
    collision_x = True
    collision_y = True

    # матрица координат транспорта
    transport_coordinates = [
        transport.get_x(),
        transport.get_x() + transport.get_width(),
        transport.get_y(),
        transport.get_y() + transport.get_height()
      ]

    # матрица координат мусорного бака
    trash_coordinates = [
        trash.get_x() + trash.get_width() / 2,
        trash.get_y() + trash.get_height() / 2
    ]

    if trash_coordinates[0] > transport_coordinates[1] or trash_coordinates[0] < transport_coordinates[0]: collision_x = False
    if trash_coordinates[1] > transport_coordinates[3] or trash_coordinates[1] < transport_coordinates[2]: collision_y = False

    if collision_x and collision_y:
        return True

    return False


# Объявление и инициализация переменных
x0, y0 = 50, 270        # Стартовые координаты для транспорта
x01, y01 = 1100, 350    # Стартовые координаты для препятствия
xNew, yNew = 0, 0       # Координаты после столкновения
radius = 10             # Вспомогательный радиус круглых фигур

bus = Bus(x0, y0, radius)               # Автобус
trolleybus = Trolleybus(x0, y0, radius) # Троллейбус
tramway = Tramway(x0, y0, radius)       # Трамвай

# Объекты после столкновения
crashed_bus = CrashedBus(x0, y0, radius)
broken_bus = BrokenBus(x0, y0, radius)
crashed_tramway = CrashedTramway(x0, y0, radius)
broken_tramway = BrokenTramway(x0, y0, radius)
crashed_trolleybus = CrashedTrolleybus(x0, y0, radius)
broken_trolleybus = BrokenTrolleybus(x0, y0, radius)

# Объекты препятствия
trash = Trash(x01, y01)
big_trash = BigTrash(x01, y01)

# Массив объектов препятствия
trashes = [trash, big_trash]
# Массив объектов транспорта
transport = [bus, trolleybus, tramway, broken_bus, broken_trolleybus, broken_tramway,
             crashed_bus, crashed_trolleybus, crashed_tramway]
# Матрица коллизий
collisions = [[3, 6],   # Автобус
              [4, 7],   # Троллейбус
              [5, 8]]   # Трамвай

# создание окна, в котором будет выполняться программа
window = gr.GraphWin('Практика программирование 4 семестр', 1980, 1200)
window.getMouse()

for iTransport in range(3):  # Проход по видам транспорта
    for iTrash in range(2):  # проход по препятствиям
        transport[iTransport].move_to(x0, y0)  # Переносим транспорт в начальные точки
        trashes[iTrash].show()  # Рисуем фигуру препятствия
        while True:
            # Двигаем фигуру транспорта
            transport[iTransport].move_to(transport[iTransport].get_x() + 50, transport[iTransport].get_y())
            # Проверка на коллизию
            if is_collision(transport[iTransport], trashes[iTrash]):
                transport[iTransport].hide()  # Прячем фигуру транспорта
                # Запоминаем новые координаты
                xNew, yNew = transport[iTransport].get_x(), transport[iTransport].get_y()
                # Вызываем объект результата коллизии
                transport[collisions[iTransport][iTrash]].move_to(xNew, yNew)
                # Показываем фигуру результата
                transport[collisions[iTransport][iTrash]].show()
                # Ожидание нажатия клавиши мыши
                window.getMouse()
                # Прячем результат коллизии
                transport[collisions[iTransport][iTrash]].hide()
                # Прячем препятствие
                trashes[iTrash].hide()
                break
window.getMouse()
window.close()

