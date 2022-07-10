"""Проектно-технологическая практика по программированию
    выполнил: студент группы М3О-210Б-20 Гаматин Илья"""

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


class ITree(Point):
    """Класс-Интерфейс ITree"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y)

    @abstractmethod
    def get_height(self):
        pass

    @abstractmethod
    def get_width(self):
        pass

    @abstractmethod
    def show(self):
        pass

    @abstractmethod
    def hide(self):
        pass


class Body(ITree):
    """Класс каркаса фигуры дерева с новыми protected полями radius, width и height"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

        self._radius = init_radius
        self._width = init_width
        self._height = init_height

    def __del__(self):
        pass

    def get_height(self):
        return self._height

    def get_width(self):
        return self._width

    def show(self):
        tree_trunk = gr.Rectangle(gr.Point(self._x - 12, self._y), gr.Point(self._x + 13, self._y + 180))
        tree_trunk.setFill('brown')

        tree_crown = gr.Circle(gr.Point(self._x, self._y), self._radius)
        tree_crown.setFill('green')

        tree_trunk.draw(window)
        tree_crown.draw(window)

    def hide(self):
        tree_trunk = gr.Rectangle(gr.Point(self._x - 12, self._y), gr.Point(self._x + 13, self._y + 180))
        tree_trunk.setFill('white')
        tree_trunk.setOutline('white')

        tree_crown = gr.Circle(gr.Point(self._x, self._y), self._radius)
        tree_crown.setFill('white')
        tree_crown.setOutline('white')

        tree_trunk.draw(window)
        tree_crown.draw(window)


class MultiTieredTree(Body):
    """Класс 1 наследника каркаса фигуры дерева(Body)"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        super(MultiTieredTree, self).show()

        tree_crown1 = gr.Circle(gr.Point(self._x - 50, self._y + 30), self._radius - 20)
        tree_crown1.setFill('green')

        tree_crown2 = gr.Circle(gr.Point(self._x + 50, self._y + 30), self._radius - 20)
        tree_crown2.setFill('green')

        tree_crown3 = gr.Circle(gr.Point(self._x, self._y + 50), self._radius - 20)
        tree_crown3.setFill('green')

        tree_crown1.draw(window)
        tree_crown2.draw(window)
        tree_crown3.draw(window)

    def hide(self):
        super(MultiTieredTree, self).hide()

        tree_crown1 = gr.Circle(gr.Point(self._x - 50, self._y + 30), self._radius - 20)
        tree_crown1.setFill('white')
        tree_crown1.setOutline('white')

        tree_crown2 = gr.Circle(gr.Point(self._x + 50, self._y + 30), self._radius - 20)
        tree_crown2.setFill('white')
        tree_crown2.setOutline('white')

        tree_crown3 = gr.Circle(gr.Point(self._x, self._y + 50), self._radius - 20)
        tree_crown3.setFill('white')
        tree_crown3.setOutline('white')

        tree_crown1.draw(window)
        tree_crown2.draw(window)
        tree_crown3.draw(window)


class IceCreamTree(Body):
    """Класс 2 наследника каркаса фигуры дерева(Body)"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        super(IceCreamTree, self).show()

        tree_crown_left = gr.Circle(gr.Point(self._x - 50, self._y + 50), self._radius - 20)
        tree_crown_left.setFill('green')

        tree_crown_right = gr.Circle(gr.Point(self._x + 50, self._y + 50), self._radius - 20)
        tree_crown_right.setFill('green')

        tree_crown_left.draw(window)
        tree_crown_right.draw(window)

    def hide(self):
        super(IceCreamTree, self).hide()

        tree_crown_left = gr.Circle(gr.Point(self._x - 50, self._y + 50), self._radius - 20)
        tree_crown_left.setFill('white')
        tree_crown_left.setOutline('white')

        tree_crown_right = gr.Circle(gr.Point(self._x + 50, self._y + 50), self._radius - 20)
        tree_crown_right.setFill('white')
        tree_crown_right.setOutline('white')

        tree_crown_left.draw(window)
        tree_crown_right.draw(window)


class DeadTree(Body):
    """Класс 3 наследника каркаса фигуры дерева(Body)"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        super(DeadTree, self).show()

        line1 = gr.Line(gr.Point(self._x - 12, self._y + 135), gr.Point(self._x - 50, self._y + 84))

        line2 = gr.Line(gr.Point(self._x + 12, self._y + 149), gr.Point(self._x + 39, self._y + 115))

        line3 = gr.Line(gr.Point(self._x - 12, self._y + 95), gr.Point(self._x - 50, self._y + 44))

        line4 = gr.Line(gr.Point(self._x + 12, self._y + 109), gr.Point(self._x + 39, self._y + 75))

        line5 = gr.Line(gr.Point(self._x + 12, self._y + 69), gr.Point(self._x + 39, self._y + 35))

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)

    def hide(self):
        super(DeadTree, self).hide()

        line1 = gr.Line(gr.Point(self._x - 12, self._y + 135), gr.Point(self._x - 50, self._y + 84))
        line1.setOutline('white')

        line2 = gr.Line(gr.Point(self._x + 12, self._y + 149), gr.Point(self._x + 39, self._y + 115))
        line2.setOutline('white')

        line3 = gr.Line(gr.Point(self._x - 12, self._y + 95), gr.Point(self._x - 50, self._y + 44))
        line3.setOutline('white')

        line4 = gr.Line(gr.Point(self._x + 12, self._y + 109), gr.Point(self._x + 39, self._y + 75))
        line4.setOutline('white')

        line5 = gr.Line(gr.Point(self._x + 12, self._y + 69), gr.Point(self._x + 39, self._y + 35))
        line5.setOutline('white')

        line1.draw(window)
        line2.draw(window)
        line3.draw(window)
        line4.draw(window)
        line5.draw(window)


class TreeWithBranch(Body):
    """Класс 4 наследника каркаса фигуры дерева(Body)"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        super(TreeWithBranch, self).show()

        line1 = gr.Line(gr.Point(self._x - 12, self._y + 135), gr.Point(self._x - 50, self._y + 84))

        line2 = gr.Line(gr.Point(self._x + 12, self._y + 149), gr.Point(self._x + 39, self._y + 115))

        tree_crown_left = gr.Circle(gr.Point(self._x - 50, self._y + 60), self._radius - 30)
        tree_crown_left.setFill('green')

        tree_crown_right = gr.Circle(gr.Point(self._x + 50, self._y + 80), self._radius - 30)
        tree_crown_right.setFill('green')

        line1.draw(window)
        line2.draw(window)
        tree_crown_left.draw(window)
        tree_crown_right.draw(window)

    def hide(self):
        super(TreeWithBranch, self).hide()

        line1 = gr.Line(gr.Point(self._x - 12, self._y + 135), gr.Point(self._x - 50, self._y + 84))
        line1.setOutline('white')

        line2 = gr.Line(gr.Point(self._x + 12, self._y + 149), gr.Point(self._x + 39, self._y + 115))
        line2.setOutline('white')

        tree_crown_left = gr.Circle(gr.Point(self._x - 50, self._y + 60), self._radius - 30)
        tree_crown_left.setFill('white')
        tree_crown_left.setOutline('white')

        tree_crown_right = gr.Circle(gr.Point(self._x + 50, self._y + 80), self._radius - 30)
        tree_crown_right.setFill('white')
        tree_crown_right.setOutline('white')

        line1.draw(window)
        line2.draw(window)
        tree_crown_left.draw(window)
        tree_crown_right.draw(window)


class AppleTree(MultiTieredTree):
    """Класс наследника фигуры дерева(MultiTieredTree)"""
    def __init__(self, init_x, init_y, init_radius, init_width, init_height):
        super().__init__(init_x, init_y, init_radius, init_width, init_height)

    def __del__(self):
        pass

    def show(self):
        super(AppleTree, self).show()

        apple1 = gr.Circle(gr.Point(self._x - 65, self._y + 60), self._radius * 0.1)
        apple1.setFill('red')

        apple2 = gr.Circle(gr.Point(self._x - 30, self._y + 100), self._radius * 0.1)
        apple2.setFill('red')

        apple3 = gr.Circle(gr.Point(self._x + 60, self._y + 70), self._radius * 0.1)
        apple3.setFill('red')

        apple4 = gr.Circle(gr.Point(self._x + 10, self._y + 60), self._radius * 0.1)
        apple4.setFill('red')

        apple1.draw(window)
        apple2.draw(window)
        apple3.draw(window)
        apple4.draw(window)

    def hide(self):
        super(AppleTree, self).hide()

        apple1 = gr.Circle(gr.Point(self._x - 65, self._y + 60), self._radius * 0.1)
        apple1.setFill('white')
        apple1.setOutline('white')

        apple2 = gr.Circle(gr.Point(self._x - 30, self._y + 100), self._radius * 0.1)
        apple2.setFill('white')
        apple2.setOutline('white')

        apple3 = gr.Circle(gr.Point(self._x + 60, self._y + 70), self._radius * 0.1)
        apple3.setFill('white')
        apple3.setOutline('white')

        apple4 = gr.Circle(gr.Point(self._x + 10, self._y + 60), self._radius * 0.1)
        apple4.setFill('white')
        apple4.setOutline('white')

        apple1.draw(window)
        apple2.draw(window)
        apple3.draw(window)
        apple4.draw(window)


class Bird(Point):
    """Класс фигуры птицы, унаследованный от класса Point,
        с новым protected полем radius"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y)

        self.radius = init_radius

    def __del__(self):
        pass

    def show(self):
        body_bird = gr.Circle(gr.Point(self._x, self._y), self.radius * 0.3)
        body_bird.setFill('blue')

        eye_bird = gr.Circle(gr.Point(self._x + 5, self._y - 5), self.radius * 0.1)
        eye_bird.setFill('white')

        beak_bird1 = gr.Line(gr.Point(self._x + 23, self._y - 10), gr.Point(self._x + 50, self._y))

        beak_bird2 = gr.Line(gr.Point(self._x + 23, self._y + 10), gr.Point(self._x + 50, self._y))

        body_bird.draw(window)
        eye_bird.draw(window)
        beak_bird1.draw(window)
        beak_bird2.draw(window)

    def hide(self):
        body_bird = gr.Circle(gr.Point(self._x, self._y), self.radius * 0.3)
        body_bird.setFill('white')
        body_bird.setOutline('white')

        eye_bird = gr.Circle(gr.Point(self._x, self._y), self.radius * 0.1)
        eye_bird.setOutline('white')
        eye_bird.setFill('white')

        beak_bird1 = gr.Line(gr.Point(self._x + 23, self._y - 10), gr.Point(self._x + 50, self._y))
        beak_bird1.setOutline('white')

        beak_bird2 = gr.Line(gr.Point(self._x + 23, self._y + 10), gr.Point(self._x + 50, self._y))
        beak_bird2.setOutline('white')

        body_bird.draw(window)
        eye_bird.draw(window)
        beak_bird1.draw(window)
        beak_bird2.draw(window)


class Water(Point):
    """Класс эффекта воды, унаследованный от класса Point,
        без дополнительных protected полей"""
    def __init__(self, init_x, init_y):
        super().__init__(init_x, init_y)

    def __del__(self):
        pass

    def show(self):
        stream1 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 17, self._y + 74))
        stream1.setOutline('blue')

        stream2 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 46, self._y + 61))
        stream2.setOutline('blue')

        stream3 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 50, self._y + 38))
        stream3.setOutline('blue')

        stream1.draw(window)
        stream2.draw(window)
        stream3.draw(window)

    def hide(self):
        stream1 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 17, self._y + 74))
        stream1.setOutline('white')

        stream2 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 46, self._y + 61))
        stream2.setOutline('white')

        stream3 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 50, self._y + 38))
        stream3.setOutline('white')

        stream1.draw(window)
        stream2.draw(window)
        stream3.draw(window)


class Acid(Water):
    """Класс эффекта кислоты, унаследованный от класса Water"""
    def __init__(self, init_x, init_y):
        super().__init__(init_x, init_y)

    def __del__(self):
        pass

    def show(self):
        stream1 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 17, self._y + 74))
        stream1.setOutline('green2')

        stream2 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 46, self._y + 61))
        stream2.setOutline('green2')

        stream3 = gr.Line(gr.Point(self._x, self._y), gr.Point(self._x + 50, self._y + 38))
        stream3.setOutline('green2')

        stream1.draw(window)
        stream2.draw(window)
        stream3.draw(window)

    def hide(self):
        super(Acid, self).hide()


class ABCCan(Point):
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


class WateringCan(ABCCan):
    """Класс лейки, унаследованный от класса Point,
        с новым protected полем radius"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        handle_watering_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.25)
        handle_watering_can.setFill('white')
        handle_watering_can.setOutline('blue')

        spout_watering_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_watering_can1.setOutline('blue')

        spout_watering_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_watering_can2.setOutline('blue')

        body_watering_can = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x + 35, self._y + 36))
        body_watering_can.setFill('blue')
        body_watering_can.setOutline('blue')

        handle_watering_can.draw(window)
        spout_watering_can1.draw(window)
        spout_watering_can2.draw(window)
        body_watering_can.draw(window)

    def hide(self):
        handle_watering_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.25)
        handle_watering_can.setFill('white')
        handle_watering_can.setOutline('white')

        spout_watering_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_watering_can1.setOutline('white')

        spout_watering_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_watering_can2.setOutline('white')

        body_watering_can = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x + 35, self._y + 36))
        body_watering_can.setFill('white')
        body_watering_can.setOutline('white')

        handle_watering_can.draw(window)
        spout_watering_can1.draw(window)
        spout_watering_can2.draw(window)
        body_watering_can.draw(window)


class AcidCan(WateringCan):
    """Класс красной лейки, унаследованный от класса WateringCan"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        handle_watering_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.25)
        handle_watering_can.setWidth(4)
        handle_watering_can.setFill('white')
        handle_watering_can.setOutline('red')

        spout_watering_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_watering_can1.setWidth(4)
        spout_watering_can1.setOutline('red')

        spout_watering_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_watering_can2.setWidth(4)
        spout_watering_can2.setOutline('red')

        body_watering_can = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x + 35, self._y + 36))
        body_watering_can.setWidth(4)
        body_watering_can.setFill('red')
        body_watering_can.setOutline('red')

        handle_watering_can.draw(window)
        spout_watering_can1.draw(window)
        spout_watering_can2.draw(window)
        body_watering_can.draw(window)

    def hide(self):
        handle_watering_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.25)
        handle_watering_can.setWidth(4)
        handle_watering_can.setFill('white')
        handle_watering_can.setOutline('white')

        spout_watering_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_watering_can1.setWidth(4)
        spout_watering_can1.setOutline('white')

        spout_watering_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_watering_can2.setWidth(4)
        spout_watering_can2.setOutline('white')

        body_watering_can = gr.Rectangle(gr.Point(self._x, self._y), gr.Point(self._x + 35, self._y + 36))
        body_watering_can.setWidth(4)
        body_watering_can.setFill('white')
        body_watering_can.setOutline('white')

        handle_watering_can.draw(window)
        spout_watering_can1.draw(window)
        spout_watering_can2.draw(window)
        body_watering_can.draw(window)


class RoundCan(WateringCan):
    """Класс круглой синей лейки, унаследованный от класса WateringCan"""
    def __init__(self, init_x, init_y, init_radius):
        super().__init__(init_x, init_y, init_radius)

    def __del__(self):
        pass

    def show(self):
        handle_round_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.3)
        handle_round_can.setWidth(4)
        handle_round_can.setFill('white')
        handle_round_can.setOutline('blue')

        spout_round_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_round_can1.setWidth(4)
        spout_round_can1.setOutline('blue')

        spout_round_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_round_can2.setWidth(4)
        spout_round_can2.setOutline('blue')

        body_round_can = gr.Circle(gr.Point(self._x + 25, self._y + 15), self._radius * 0.3)
        body_round_can.setWidth(4)
        body_round_can.setFill('blue')
        body_round_can.setOutline('blue')

        handle_round_can.draw(window)
        spout_round_can1.draw(window)
        spout_round_can2.draw(window)
        body_round_can.draw(window)

    def hide(self):
        handle_round_can = gr.Circle(gr.Point(self._x - 6, self._y - 4), self._radius * 0.3)
        handle_round_can.setWidth(4)
        handle_round_can.setFill('white')
        handle_round_can.setOutline('white')

        spout_round_can1 = gr.Line(gr.Point(self._x + 34, self._y + 18), gr.Point(self._x + 80, self._y))
        spout_round_can1.setWidth(4)
        spout_round_can1.setOutline('white')

        spout_round_can2 = gr.Line(gr.Point(self._x + 34, self._y), gr.Point(self._x + 80, self._y))
        spout_round_can2.setWidth(4)
        spout_round_can2.setOutline('white')

        body_round_can = gr.Circle(gr.Point(self._x + 20, self._y + 15), self._radius * 0.3)
        body_round_can.setWidth(4)
        body_round_can.setFill('white')
        body_round_can.setOutline('white')

        handle_round_can.draw(window)
        spout_round_can1.draw(window)
        spout_round_can2.draw(window)
        body_round_can.draw(window)


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


# начало блока выполнения программы

# задание координат, радиуса и т.д.
x, y = 400, 400
radius = 80
width = 200
height = 200

# инициализация объектов классов
ACan = WateringCan(x - 150, y, radius)
BCan = AcidCan(x - 150, y, radius)
FirstTree = Body(x, y, radius, width, height)
SecondTree = TreeWithBranch(x, y, radius, width, height)
ThirdTree = IceCreamTree(x, y, radius, width, height)
FourthTree = MultiTieredTree(x, y, radius, width, height)
LastTree = AppleTree(x, y, radius, width, height)
WaterFall = Water(x, y)
AAcid = Acid(x - 40, y)
ABird = Bird(x - 200, y - 150, radius)

PostLastTree = DeadTree(x, y, radius, width, height)
ARoundCan = RoundCan(x - 150, y, radius)

# объявление массивов объектов для организации их взаимодействий
# figureTree - массив деревьев, участвующих во взаимодействиях
# figureMove - массив объектов, передвигающихся и участвующих во взаимодействиях
figureTree = [FirstTree, SecondTree, ThirdTree, FourthTree, LastTree, PostLastTree]
figureMove = [ACan, BCan, ABird, ARoundCan]

# событийная матрица CollisionCase,
# каждая цифра соответствует номеру дерева,
# которое вызывается в результате столкновения объектов.
# значение "-1" означает пропуск взаимодействия n-ого и m-ого объектов
CollisionCase = [[1, 2, 3, 4, -1, -1],      # проход по деревьям лейкой с водой
                 [-1, 0, 1, 2, 3, -1],      # проход по деревьям лейкой с кислотой
                 [4, 4, 4, 4, 4, 4],        # проход по деревьям птицей
                 [-1, -1, -1, -1, -1, 1]]   # проход по деревьям круглой лейкой (доп задание)

# создание окна, в котором будет выполняться программа
window = gr.GraphWin('Практика программирование 4 семестр', 1000, 1000)
window.getMouse()
# основной цикл выполнения
for iMove in range(4):
    for iTree in range(6):
        if CollisionCase[iMove][iTree] == -1:
            continue
        figureTree[iTree].show()
        figureMove[iMove].move_to(x - 150, y)
        figureMove[iMove].show()
        while True:
            figureMove[iMove].move_to(figureMove[iMove].get_x() + 5, figureMove[iMove].get_y())
            if collision(figureTree[iTree], figureMove[iMove]):
                if iMove == 0 or iMove == 3:
                    WaterFall.move_to(figureMove[iMove].get_x() + 80, figureMove[iMove].get_y())
                    WaterFall.show()
                    time.sleep(0.1)
                    WaterFall.hide()
                if iMove == 1:
                    AAcid.move_to(figureMove[iMove].get_x() + 80, figureMove[iMove].get_y())
                    AAcid.show()
                    time.sleep(0.1)
                    AAcid.hide()
                figureTree[iTree].hide()
                time.sleep(1)
                figureMove[iMove].hide()
                figureTree[CollisionCase[iMove][iTree]].show()
                figureMove[iMove].show()
                time.sleep(1)
                figureTree[CollisionCase[iMove][iTree]].hide()
                break
        figureTree[iTree].hide()
window.getMouse()
# завершение программы
window.close()
