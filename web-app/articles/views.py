from django.shortcuts import render

def article_list(request):
    return render(request,'articles/article_list.html')
def contact(request):
    return render(request,'articles/contact.html')
