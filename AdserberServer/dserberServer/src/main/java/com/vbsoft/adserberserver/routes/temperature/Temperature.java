package com.vbsoft.adserberserver.routes.temperature;

import com.vaadin.flow.component.html.Label;
import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component("temperature")
@Scope(BeanDefinition.SCOPE_PROTOTYPE)
public class Temperature extends VerticalLayout {

    public Temperature() {

        Label text = new Label("aaaa");
        add(text);

    }
}
