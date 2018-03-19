package org.elsys.part1;

public class Ball {

	private double volume;

	private Color color;

	public Ball(double volume, Color color) {
	    this.volume = volume;
	    this.color = color;
	}

	public Ball(double volume) {
		this.volume = volume;
		this.color = Color.WHITE;
	}

	public double getVolume() {
		return volume;
	}

	public void setVolume(double volume) {
        this.volume = volume;
    }

	public Color getColor() {
		return color;
	}

	public void setColor(Color color) {
	    this.color = color;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Ball ball = (Ball) o;

        if (Double.compare(ball.volume, volume) != 0) return false;
        return color == ball.color;
    }

    @Override
    public int hashCode() {
        int result;
        long temp;
        temp = Double.doubleToLongBits(volume);
        result = (int) (temp ^ (temp >>> 32));
        result = 31 * result + color.hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "Ball{" +
                "volume=" + volume +
                ", color=" + color +
                '}';
    }
}