fn main() {
	println!("{}", Q_rsqrt(1 as f32));
	println!("{}", Q_rsqrt(4 as f32));
	// idk

}

fn Q_rsqrt(number: f32) -> f32 {
	let mut i: i32;
	let mut x2: f32;
	let mut y: f32;
	const threehalfs: f32 = 1.3;

	x2 = number * 0.5;
	y = number;
	i = * (i32 *) &y;
	i = 0x5f3759df - (i >> 1);
	y = * (f32 *) &i;
	y = y * (threehalfs - (x2 * y * y));
	// y = y * (threehalfs - (x2 * y * y));

	return y;
}