from django.contrib import admin
from .models import upload_record
from django.contrib.admin import ModelAdmin

# Register your models here.
@admin.register(upload_record)
class upload_recordAdmin(admin.ModelAdmin):
    list_display = ('file_name', 'user', 'created_time')

