# مشکل انتصاب (Assignment Problem)
برای حل این مشکل ما دو الگوریتم پیشنهاد کردیم. جواب تمرین کد گریدی ما است اما این کد جواب بهینه را به ما نمیدهد. جواب بهینه جواب حاصل از الگوریتم مجارستانی می‌باشد.
<br><br>

## الگوریتم Greedy
کد این روش در
<a href='https://github.com/EnAnsari/algorithm-hsu/blob/main/src/1402-1/practices/2/question-4/greedy.py'>این لینک +</a>
موجود است.<br>
این روش ممکن است جواب بهینه را به ما ندهد. مرتبه زمانی این الگوریتم O(n^2) می‌باشد.

### توضیح الگوریتم


- در روش حریصانه در هر سری کوچکترین هزینه برای کار هر شخص را به عنوان به عنوان بهترین کار برای آن شخص مشخص می‌کنیم.<br>
- در هر مرحله پس از مشخص شدن کار شخص به صورت گریدی دیگر آن کار را رزرو شده در نظر گرفته و دیگر آن کار را برای شخص دیگری در نظر نمیگیریم. (به همین خاطر ممکن است بهینه‌ترین جواب را نداشته باشیم.)<br>
- در نهایت جواب را چاپ ‌می‌کنیم.

<br>

## الگوریتم Hungarian
کد این روش به زودی آپلود می‌شود.<br>
با استفاده از این روش میتوانیم به جواب صد در صد درست برسیم. مرتبه زمانی این الگوریتم O(n^3) می‌باشد.