import graphics as gr
import time
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
        # метод super() необходим для наследования полей родительских классов
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


class ITV(Point):
    """Класс-интерфейс ITV.
     Здесь показываются поля width и height, но не инициализируются"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y)

    @abstractmethod
    def __del__(self):
        pass

    @abstractmethod
    def get_width(self):
        pass

    @abstractmethod
    def get_height(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def hide(self):
        pass


class PlasmaTV(Point):
    """Класс самого простого плазменного телевизора"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y)
        self._width = init_width
        self._height = init_height

    def __del__(self):
        pass

    def get_width(self):
        return self._width

    def get_height(self):
        return self._height

    def show(self):
        self._visible = True
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                             gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))

        rect1.draw(window)
        rect2.draw(window)

    def hide(self):
        self._visible = False
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect1.setOutline('white')
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                             gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        rect2.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)


class PlasmaTVwLegs(PlasmaTV):
    """Класс телевизора с ножками"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        # метод super() позволяет вызывать методы show() и hide() родительского класса
        super(PlasmaTVwLegs, self).show()

        rect1 = gr.Rectangle(gr.Point(self._x - 135, self._y + 75), gr.Point(self._x - 125, self._y + 95))
        rect2 = gr.Rectangle(gr.Point(self._x + 125, self._y + 75), gr.Point(self._x + 135, self._y + 95))
        rect3 = gr.Rectangle(gr.Point(self._x - 185, self._y + 95), gr.Point(self._x + 185, self._y + 105))

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVwLegs, self).hide()

        rect1 = gr.Rectangle(gr.Point(self._x - 135, self._y + 75), gr.Point(self._x - 125, self._y + 95))
        rect1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x + 125, self._y + 75), gr.Point(self._x + 135, self._y + 95))
        rect2.setOutline('white')

        rect3 = gr.Rectangle(gr.Point(self._x - 185, self._y + 95), gr.Point(self._x + 185, self._y + 105))
        rect3.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)


class PlasmaTVonStand(PlasmaTVwLegs):
    """Класс телевизора на комоде"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVonStand, self).show()

        rect1 = gr.Rectangle(gr.Point(self._x - 190, self._y + 105), gr.Point(self._x + 190, self._y + 155))
        rect2 = gr.Rectangle(gr.Point(self._x - 110, self._y + 130), gr.Point(self._x + 110, self._y + 140))
        rect3 = gr.Rectangle(gr.Point(self._x - 190, self._y + 155), gr.Point(self._x + 190, self._y + 205))
        rect4 = gr.Rectangle(gr.Point(self._x - 110, self._y + 180), gr.Point(self._x + 110, self._y + 190))
        rect5 = gr.Rectangle(gr.Point(self._x - 190, self._y + 205), gr.Point(self._x + 190, self._y + 255))
        rect6 = gr.Rectangle(gr.Point(self._x - 110, self._y + 230), gr.Point(self._x + 110, self._y + 240))

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        rect5.draw(window)
        rect6.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVonStand, self).hide()

        rect1 = gr.Rectangle(gr.Point(self._x - 190, self._y + 105), gr.Point(self._x + 190, self._y + 155))
        rect1.setOutline('white')
        rect2 = gr.Rectangle(gr.Point(self._x - 110, self._y + 130), gr.Point(self._x + 110, self._y + 140))
        rect2.setOutline('white')
        rect3 = gr.Rectangle(gr.Point(self._x - 190, self._y + 155), gr.Point(self._x + 190, self._y + 205))
        rect3.setOutline('white')
        rect4 = gr.Rectangle(gr.Point(self._x - 110, self._y + 180), gr.Point(self._x + 110, self._y + 190))
        rect4.setOutline('white')
        rect5 = gr.Rectangle(gr.Point(self._x - 190, self._y + 205), gr.Point(self._x + 190, self._y + 255))
        rect5.setOutline('white')
        rect6 = gr.Rectangle(gr.Point(self._x - 110, self._y + 230), gr.Point(self._x + 110, self._y + 240))
        rect6.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        rect5.draw(window)
        rect6.draw(window)


class PlasmaTVScreenOff(PlasmaTVonStand):
    """Класс телевизора с выключенным экраном"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVScreenOff, self).show()

        line1 = gr.Line(gr.Point(self._x - 145, self._y - 20), gr.Point(self._x + 145, self._y - 20))
        line2 = gr.Line(gr.Point(self._x + 145, self._y - 20), gr.Point(self._x - 125, self._y - 10))
        line3 = gr.Line(gr.Point(self._x - 125, self._y - 10), gr.Point(self._x + 125, self._y - 10))
        line4 = gr.Line(gr.Point(self._x + 125, self._y - 10), gr.Point(self._x - 105, self._y))
        line5 = gr.Line(gr.Point(self._x - 105, self._y), gr.Point(self._x - 85, self._y + 10))
        line6 = gr.Line(gr.Point(self._x - 85, self._y + 10), gr.Point(self._x + 85, self._y + 10))
        line7 = gr.Line(gr.Point(self._x + 85, self._y + 10), gr.Point(self._x - 65, self._y + 20))
        line8 = gr.Line(gr.Point(self._x - 65, self._y + 20), gr.Point(self._x + 65, self._y + 20))

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)
        line6.draw(window)
        line7.draw(window)
        line8.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVScreenOff, self).hide()

        line1 = gr.Line(gr.Point(self._x - 145, self._y - 20), gr.Point(self._x + 145, self._y - 20))
        line1.setOutline('white')

        line2 = gr.Line(gr.Point(self._x + 145, self._y - 20), gr.Point(self._x - 125, self._y - 10))
        line2.setOutline('white')

        line3 = gr.Line(gr.Point(self._x - 125, self._y - 10), gr.Point(self._x + 125, self._y - 10))
        line3.setOutline('white')

        line4 = gr.Line(gr.Point(self._x + 125, self._y - 10), gr.Point(self._x - 105, self._y))
        line4.setOutline('white')

        line5 = gr.Line(gr.Point(self._x - 105, self._y), gr.Point(self._x - 85, self._y + 10))
        line5.setOutline('white')

        line6 = gr.Line(gr.Point(self._x - 85, self._y + 10), gr.Point(self._x + 85, self._y + 10))
        line6.setOutline('white')

        line7 = gr.Line(gr.Point(self._x + 85, self._y + 10), gr.Point(self._x - 65, self._y + 20))
        line7.setOutline('white')

        line8 = gr.Line(gr.Point(self._x - 65, self._y + 20), gr.Point(self._x + 65, self._y + 20))
        line8.setOutline('white')

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)
        line6.draw(window)
        line7.draw(window)
        line8.draw(window)


class PlasmaTVScreenOn(PlasmaTVonStand):
    """Класс телевизора с включенным экраном"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)
        self._radius = 15

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVScreenOn, self).show()

        rect1 = gr.Rectangle(gr.Point(self._x - 45, self._y - 30), gr.Point(self._x + 30, self._y + 30))
        circle1 = gr.Circle(gr.Point(self._x - 25, self._y - 15), self._radius)
        rect2 = gr.Rectangle(gr.Point(self._x - 10, self._y + 5), gr.Point(self._x + 10, self._y + 15))
        circle2 = gr.Circle(gr.Point(self._x + 25, self._y - 15), self._radius)

        rect1.draw(window)
        rect2.draw(window)
        circle1.draw(window)
        circle2.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVScreenOn, self).hide()

        rect1 = gr.Rectangle(gr.Point(self._x - 45, self._y - 30), gr.Point(self._x + 30, self._y + 30))
        rect1.setOutline('white')

        circle1 = gr.Circle(gr.Point(self._x - 25, self._y - 15), self._radius)
        circle1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x - 10, self._y + 5), gr.Point(self._x + 10, self._y + 15))
        rect2.setOutline('white')

        circle2 = gr.Circle(gr.Point(self._x + 25, self._y - 15), self._radius)
        circle2.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        circle1.draw(window)
        circle2.draw(window)


class PlasmaTVExtra(PlasmaTVonStand):
    """Класс телевизора с дополнением"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVExtra, self).show()

        rect1 = gr.Rectangle(gr.Point(self._x - 75, self._y - 50), gr.Point(self._x + 75, self._y + 50))
        rect2 = gr.Rectangle(gr.Point(self._x - 65, self._y - 40), gr.Point(self._x + 65, self._y + 40))
        rect3 = gr.Rectangle(gr.Point(self._x - 50, self._y - 30), gr.Point(self._x + 50, self._y + 30))
        rect4 = gr.Rectangle(gr.Point(self._x - 35, self._y - 20), gr.Point(self._x + 35, self._y + 20))
        rect5 = gr.Rectangle(gr.Point(self._x - 15, self._y - 5), gr.Point(self._x + 15, self._y + 5))

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        rect5.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVExtra, self).hide()

        rect1 = gr.Rectangle(gr.Point(self._x - 75, self._y - 50), gr.Point(self._x + 75, self._y + 50))
        rect1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x - 65, self._y - 40), gr.Point(self._x + 65, self._y + 40))
        rect2.setOutline('white')

        rect3 = gr.Rectangle(gr.Point(self._x - 50, self._y - 30), gr.Point(self._x + 50, self._y + 30))
        rect3.setOutline('white')

        rect4 = gr.Rectangle(gr.Point(self._x - 35, self._y - 20), gr.Point(self._x + 35, self._y + 20))
        rect4.setOutline('white')

        rect5 = gr.Rectangle(gr.Point(self._x - 15, self._y - 5), gr.Point(self._x + 15, self._y + 5))
        rect5.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        rect5.draw(window)


class PlasmaTVColorScreen(PlasmaTVonStand):
    """Класс телевизора с красным экраном"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVColorScreen, self).show()

        screen = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                              gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        screen.setFill('red')

        screen.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVColorScreen, self).hide()

        screen = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                              gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        screen.setFill('white')
        screen.setOutline('white')

        screen.draw(window)


class PlasmaTVBroken(PlasmaTVonStand):
    """Класс телевизора со сломанным экраном"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVBroken, self).show()

        line1 = gr.Line(gr.Point(self._x - 100, self._y - self._height / 2 + 5),
                        gr.Point(self._x - 115, self._y - self._height / 2 + 30))
        line2 = gr.Line(gr.Point(self._x - 115, self._y - self._height / 2 + 30),
                        gr.Point(self._x - 90, self._y - self._height / 2 + 30))
        line3 = gr.Line(gr.Point(self._x - 90, self._y - self._height / 2 + 30),
                        gr.Point(self._x - 100, self._y - self._height / 2 + 60))

        line4 = gr.Line(gr.Point(self._x + 100, self._y - self._height / 2 + 5),
                        gr.Point(self._x + 115, self._y - self._height / 2 + 30))
        line5 = gr.Line(gr.Point(self._x + 115, self._y - self._height / 2 + 30),
                        gr.Point(self._x + 90, self._y - self._height / 2 + 30))
        line6 = gr.Line(gr.Point(self._x + 90, self._y - self._height / 2 + 30),
                        gr.Point(self._x + 100, self._y - self._height / 2 + 60))

        line7 = gr.Line(gr.Point(self._x, self._y + self._height / 2 - 5),
                        gr.Point(self._x - 15, self._y + self._height / 2 - 30))
        line8 = gr.Line(gr.Point(self._x - 15, self._y + self._height / 2 - 30),
                        gr.Point(self._x + 15, self._y + self._height / 2 - 30))
        line9 = gr.Line(gr.Point(self._x + 15, self._y + self._height / 2 - 30),
                        gr.Point(self._x, self._y + self._height / 2 - 60))

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)
        line6.draw(window)
        line7.draw(window)
        line8.draw(window)
        line9.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVBroken, self).hide()

        line1 = gr.Line(gr.Point(self._x - 100, self._y - self._height / 2 + 5),
                        gr.Point(self._x - 115, self._y - self._height / 2 + 30))
        line1.setOutline('white')
        line2 = gr.Line(gr.Point(self._x - 115, self._y - self._height / 2 + 30),
                        gr.Point(self._x - 90, self._y - self._height / 2 + 30))
        line2.setOutline('white')
        line3 = gr.Line(gr.Point(self._x - 90, self._y - self._height / 2 + 30),
                        gr.Point(self._x - 100, self._y - self._height / 2 + 60))
        line3.setOutline('white')

        line4 = gr.Line(gr.Point(self._x + 100, self._y - self._height / 2 + 5),
                        gr.Point(self._x + 115, self._y - self._height / 2 + 30))
        line4.setOutline('white')
        line5 = gr.Line(gr.Point(self._x + 115, self._y - self._height / 2 + 30),
                        gr.Point(self._x + 90, self._y - self._height / 2 + 30))
        line5.setOutline('white')
        line6 = gr.Line(gr.Point(self._x + 90, self._y - self._height / 2 + 30),
                        gr.Point(self._x + 100, self._y - self._height / 2 + 60))
        line6.setOutline('white')

        line7 = gr.Line(gr.Point(self._x, self._y + self._height / 2 - 5),
                        gr.Point(self._x - 15, self._y + self._height / 2 - 30))
        line7.setOutline('white')
        line8 = gr.Line(gr.Point(self._x - 15, self._y + self._height / 2 - 30),
                        gr.Point(self._x + 15, self._y + self._height / 2 - 30))
        line8.setOutline('white')
        line9 = gr.Line(gr.Point(self._x + 15, self._y + self._height / 2 - 30),
                        gr.Point(self._x, self._y + self._height / 2 - 60))
        line9.setOutline('white')

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)
        line6.draw(window)
        line7.draw(window)
        line8.draw(window)
        line9.draw(window)


class PlasmaTVBlueScreen(PlasmaTVonStand):
    """Класс телевизора с синим экраном"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        super(PlasmaTVBlueScreen, self).show()

        screen = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                              gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        screen.setFill('blue')

        screen.draw(window)

    def hide(self):
        self._visible = False
        super(PlasmaTVBlueScreen, self).hide()

        screen = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                              gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        screen.setFill('white')
        screen.setOutline('white')

        screen.draw(window)


class ABCFigure(Point):
    """Абстрактный класс ABCFigure, родительский для классов пультов ДУ"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y)
        self._width = init_width
        self._height = init_height

    @abstractmethod
    def __del__(self):
        pass

    @abstractmethod
    def get_width(self):
        pass

    @abstractmethod
    def get_height(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def hide(self):
        pass


class Remote(ABCFigure):
    """Класс простого пульта ДУ"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)
        self._width = init_width
        self._height = init_height
        self._radius = 10

    def __del__(self):
        pass

    def get_width(self):
        return self._width

    def get_height(self):
        return self._height

    def show(self):
        self._visible = True
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 3, self._y - self._height / 2 + 3),
                             gr.Point(self._x + self._width / 2 - 3, self._y + self._height / 2 - 3))

        circle1 = gr.Circle(gr.Point(self._x, self._y - 22), self._radius)
        circle2 = gr.Circle(gr.Point(self._x, self._y - 2), self._radius)

        rect3 = gr.Rectangle(gr.Point(self._x - 8, self._y + 10), gr.Point(self._x + 8, self._y + 20))
        rect4 = gr.Rectangle(gr.Point(self._x - 8, self._y + 20), gr.Point(self._x + 8, self._y + 30))

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        circle1.draw(window)
        circle2.draw(window)

    def hide(self):
        self._visible = False
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect1.setOutline('white')
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 3, self._y - self._height / 2 + 3),
                             gr.Point(self._x + self._width / 2 - 3, self._y + self._height / 2 - 3))
        rect2.setOutline('white')

        circle1 = gr.Circle(gr.Point(self._x, self._y - 22), self._radius)
        circle1.setOutline('white')

        circle2 = gr.Circle(gr.Point(self._x, self._y - 2), self._radius)
        circle2.setOutline('white')

        rect3 = gr.Rectangle(gr.Point(self._x - 8, self._y + 10), gr.Point(self._x + 8, self._y + 20))
        rect3.setOutline('white')

        rect4 = gr.Rectangle(gr.Point(self._x - 8, self._y + 20), gr.Point(self._x + 8, self._y + 30))
        rect4.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        circle1.draw(window)
        circle2.draw(window)


class RemoteOld(Remote):
    """Класс старого пульта"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)
        self._radius = 8

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                             gr.Point(self._x + self._width / 2 - 5, self._y + height / 2 - 5))
        rect3 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 30),
                             gr.Point(self._x + self._width / 2 - 5, self._y + height / 2 - 30))
        rect4 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 40),
                             gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 20))

        circle = gr.Circle(gr.Point(self._x, self._y - 21), self._radius)

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        circle.draw(window)

    def hide(self):
        self._visible = False
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                             gr.Point(self._x + self._width / 2 - 5, self._y + height / 2 - 5))
        rect2.setOutline('white')

        rect3 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 30),
                             gr.Point(self._x + self._width / 2 - 5, self._y + height / 2 - 30))
        rect3.setOutline('white')

        rect4 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 40),
                             gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 20))
        rect4.setOutline('white')

        circle = gr.Circle(gr.Point(self._x, self._y - 21), self._radius)
        circle.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        rect3.draw(window)
        rect4.draw(window)
        circle.draw(window)


class RemoteNew(Remote):
    """Класс нового пульта"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)
        self._radius = 10

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 3, self._y - self._height / 2 + 3),
                             gr.Point(self._x + self._width / 2 - 3, self._y + self._height / 2 - 3))
        circle1 = gr.Circle(gr.Point(self._x, self._y - 22), self._radius)
        circle2 = gr.Circle(gr.Point(self._x, self._y - 2), self._radius)
        circle3 = gr.Circle(gr.Point(self._x, self._y + 18), self._radius)

        rect1.draw(window)
        rect2.draw(window)
        circle1.draw(window)
        circle2.draw(window)
        circle3.draw(window)

    def hide(self):
        self._visible = False
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                             gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        rect1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 3, self._y - self._height / 2 + 3),
                             gr.Point(self._x + self._width / 2 - 3, self._y + self._height / 2 - 3))
        rect2.setOutline('white')

        circle1 = gr.Circle(gr.Point(self._x, self._y - 22), self._radius)
        circle1.setOutline('white')

        circle2 = gr.Circle(gr.Point(self._x, self._y - 2), self._radius)
        circle2.setOutline('white')

        circle3 = gr.Circle(gr.Point(self._x, self._y + 18), self._radius)
        circle3.setOutline('white')

        rect1.draw(window)
        rect2.draw(window)
        circle1.draw(window)
        circle2.draw(window)
        circle3.draw(window)


class RemoteExtra(Remote):
    """Класс пульта с дополнением"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)
        self._radius = 1

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        oval1 = gr.Oval(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                        gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        oval2 = gr.Oval(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                        gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 10, self._y - self._height / 2 + 10),
                             gr.Point(self._x + self._width / 2 - 10, self._y + self._height / 2 - 10))
        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 15, self._y - self._height / 2 + 15),
                             gr.Point(self._x + self._width / 2 - 15, self._y + self._height / 2 - 15))

        oval1.draw(window)
        oval2.draw(window)
        rect1.draw(window)
        rect2.draw(window)

    def hide(self):
        self._visible = False
        oval1 = gr.Oval(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                        gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        oval1.setOutline('white')

        oval2 = gr.Oval(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                        gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        oval2.setOutline('white')

        rect1 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 10, self._y - self._height / 2 + 10),
                             gr.Point(self._x + self._width / 2 - 10, self._y + self._height / 2 - 10))
        rect1.setOutline('white')

        rect2 = gr.Rectangle(gr.Point(self._x - self._width / 2 + 15, self._y - self._height / 2 + 15),
                             gr.Point(self._x + self._width / 2 - 15, self._y + self._height / 2 - 15))
        rect2.setOutline('white')

        oval1.draw(window)
        oval2.draw(window)
        rect1.draw(window)
        rect2.draw(window)


class RemoteRound(Remote):
    """Класс круглого пульта"""
    def __init__(self, init_x, init_y, init_width, init_height):
        super().__init__(init_x, init_y, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        self._visible = True
        oval1 = gr.Oval(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                        gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        oval2 = gr.Oval(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                        gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))

        oval1.draw(window)
        oval2.draw(window)

    def hide(self):
        self._visible = False
        oval1 = gr.Oval(gr.Point(self._x - self._width / 2, self._y - self._height / 2),
                        gr.Point(self._x + self._width / 2, self._y + self._height / 2))
        oval1.setOutline('white')

        oval2 = gr.Oval(gr.Point(self._x - self._width / 2 + 5, self._y - self._height / 2 + 5),
                        gr.Point(self._x + self._width / 2 - 5, self._y + self._height / 2 - 5))
        oval2.setOutline('white')

        oval1.draw(window)
        oval2.draw(window)


def collision(figure1, figure2):
    """Функция столкновения двух объектов в ходе выполнения программы"""
    x_coll = False
    y_coll = False

    f1_width = figure1.get_width()
    f1_height = figure1.get_height()
    f1_x = figure1.get_x() - f1_width / 2
    f1_y = figure1.get_y() - f1_height / 2

    f2_x = figure2.get_x()
    f2_y = figure2.get_y()

    if (f1_x + f1_width >= f2_x) and (f1_x <= f2_x):
        x_coll = True
    if (f1_y + f1_height >= f2_y) and (f1_y <= f2_y):
        y_coll = True

    if x_coll and y_coll:
        print('Collision!')
        return True
    return False


# Инициализация переменных
x0, y0 = 525, 175                       # Координаты телевизора
width, height = 350, 150                # Ширина и высота телевизора
remote_x0, remote_y0 = 150, 175         # Координаты пульта
remote_width, remote_height = 30, 70    # Ширина и высота пульта

# Создание объектов телевизоров
Tv = PlasmaTV(x0, y0, width, height)
TvwLegs = PlasmaTVwLegs(x0, y0, width, height)
TvonStand = PlasmaTVonStand(x0, y0, width, height)
TvOn = PlasmaTVScreenOn(x0, y0, width, height)
TvOff = PlasmaTVScreenOff(x0, y0, width, height)
TvBroken = PlasmaTVBroken(x0, y0, width, height)
TvRed = PlasmaTVColorScreen(x0, y0, width, height)
TvBlue = PlasmaTVBlueScreen(x0, y0, width, height)
TvExtra = PlasmaTVExtra(x0, y0, width, height)

# Создание объектов пультов ДУ
Remote1 = Remote(remote_x0, remote_y0, remote_width, remote_height)
RemoteNew = RemoteNew(remote_x0, remote_y0, remote_width + 15, remote_height + 15)
RemoteOld = RemoteOld(remote_x0, remote_y0, remote_width - 10, remote_height - 10)
RemoteRound = RemoteRound(remote_x0, remote_y0, 20, 30)
RemoteExtra = RemoteExtra(remote_x0, remote_y0, 50, 50)

# Массивы телевизоров и пультов для проигрывания цикла
figureTV = [TvonStand, TvOn, TvOff, TvExtra, TvRed, TvBlue, TvBroken]
figureRm = [Remote1, RemoteNew, RemoteOld, RemoteRound, RemoteExtra]

# Матрица коллизий между объектами телевизоров и пультов
CollisionCase = [[3, 4, 5, 3, 5],
                 [4, 5, 3, 4, 5],
                 [5, 4, 5, 3, 4],
                 [3, 3, 4, 5, 5]]

# Создание окна программы
window = gr.GraphWin('Практика программирование 4 семестр', 1800, 1200)

# Ожидание клика мыши
window.getMouse()
for iRemote in range(5):
    for iTV in range(4):
        figureTV[iTV].show()
        time.sleep(2)
        figureRm[iRemote].show()

        while True:
            # Движение пульта до телевизора
            figureRm[iRemote].move_to(figureRm[iRemote].get_x() + 10, figureRm[iRemote].get_y())
            # Проверка столкновения
            if collision(figureTV[iTV], figureRm[iRemote]):
                figureTV[iTV].hide()
                time.sleep(2)
                figureTV[CollisionCase[iTV][iRemote]].show()
                break
        time.sleep(2)
        # Возврат пульта на начальную позицию
        figureRm[iRemote].move_to(remote_x0, remote_y0)
        figureTV[CollisionCase[iTV][iRemote]].hide()
        time.sleep(2)
        figureRm[iRemote].hide()
window.getMouse()
# завершение программы
window.close()
