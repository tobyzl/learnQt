在画刷中可以使用渐变填充。QGradient类就是用来和QBrush一起指定渐变填充的。Qt现在支持三种类型的渐变填充：

? 线性渐变（linear gradient）在开始点和结束点之间插入颜色；
?辐射渐变（radial gradient）在焦点和环绕它的圆环间插入颜色；
?锥形渐变（Conical）在圆心周围插入颜色。



这三种渐变分别由QGradient的三个子类来表示，QLinearGradient表示线性渐变，QRadialGradient表示辐射渐变，QConicalGradient表示锥形渐变。