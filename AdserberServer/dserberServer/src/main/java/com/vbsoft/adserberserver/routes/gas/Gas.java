package com.vbsoft.adserberserver.routes.gas;

import com.vaadin.flow.component.orderedlayout.VerticalLayout;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component("gas")
@Scope(BeanDefinition.SCOPE_PROTOTYPE)
public class Gas extends VerticalLayout {
}
